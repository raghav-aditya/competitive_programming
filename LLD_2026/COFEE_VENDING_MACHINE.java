import java.util.*;
import java.util.concurrent.ConcurrentHashMap;

enum CoffeeType {
    ESPRESSO, LATTE, CAPPUCCINO
}

class Recipe {
    Map<String, Integer> ingredients = new HashMap<>();

    public Recipe addIngredient(String name, int qty) {
        ingredients.put(name, qty);
        return this;
    }

    public Map<String, Integer> getIngredients() {
        return ingredients;
    }
}

class Coffee {
    CoffeeType type;
    int price;
    Recipe recipe;

    Coffee(CoffeeType type, int price, Recipe recipe) {
        this.type = type;
        this.price = price;
        this.recipe = recipe;
    }
}

class Inventory {
    private Map<String, Integer> stock = new ConcurrentHashMap<>();
    private final int LOW_THRESHOLD = 10;

    public Inventory() {
        stock.put("water", 100);
        stock.put("milk", 100);
        stock.put("coffee", 100);
    }

    // synchronized to ensure atomic check + update
    public synchronized boolean hasIngredients(Recipe recipe) {
        for (Map.Entry<String, Integer> e : recipe.getIngredients().entrySet()) {
            if (stock.getOrDefault(e.getKey(), 0) < e.getValue()) {
                return false;
            }
        }
        return true;
    }

    public synchronized void deductIngredients(Recipe recipe) {
        for (Map.Entry<String, Integer> e : recipe.getIngredients().entrySet()) {
            stock.put(e.getKey(), stock.get(e.getKey()) - e.getValue());

            if (stock.get(e.getKey()) < LOW_THRESHOLD) {
                System.out.println("Low inventory for: " + e.getKey());
            }
        }
    }
}

class PaymentService {

    public boolean processPayment(int amountPaid, int price) {
        return amountPaid >= price;
    }

    public int getChange(int amountPaid, int price) {
        return amountPaid - price;
    }
}

class CoffeeMachine {

    private Map<CoffeeType, Coffee> menu = new HashMap<>();
    private Inventory inventory = new Inventory();
    private PaymentService paymentService = new PaymentService();

    public CoffeeMachine() {
        initMenu();
    }

    private void initMenu() {
        menu.put(CoffeeType.ESPRESSO,
                new Coffee(CoffeeType.ESPRESSO, 50,
                        new Recipe().addIngredient("water", 10).addIngredient("coffee", 5)));

        menu.put(CoffeeType.LATTE,
                new Coffee(CoffeeType.LATTE, 70,
                        new Recipe().addIngredient("water", 10).addIngredient("coffee", 5).addIngredient("milk", 10)));

        menu.put(CoffeeType.CAPPUCCINO,
                new Coffee(CoffeeType.CAPPUCCINO, 80,
                        new Recipe().addIngredient("water", 10).addIngredient("coffee", 5).addIngredient("milk", 15)));
    }

    public void displayMenu() {
        for (Coffee c : menu.values()) {
            System.out.println(c.type + " : ₹" + c.price);
        }
    }

    // synchronized → handles concurrent requests safely
    public synchronized void orderCoffee(CoffeeType type, int amountPaid) {
        Coffee coffee = menu.get(type);

        if (coffee == null) {
            System.out.println("Invalid selection");
            return;
        }

        // Check inventory
        if (!inventory.hasIngredients(coffee.recipe)) {
            System.out.println("Insufficient ingredients");
            return;
        }

        // Process payment
        if (!paymentService.processPayment(amountPaid, coffee.price)) {
            System.out.println("Insufficient payment");
            return;
        }

        // Deduct ingredients
        inventory.deductIngredients(coffee.recipe);

        // Dispense coffee
        System.out.println("Dispensing " + type);

        int change = paymentService.getChange(amountPaid, coffee.price);
        if (change > 0) {
            System.out.println("Returning change: ₹" + change);
        }
    }
}

public class Main {
    public static void main(String[] args) {

        CoffeeMachine machine = new CoffeeMachine();
        machine.displayMenu();

        // Simulate concurrent users
        Runnable user1 = () -> machine.orderCoffee(CoffeeType.LATTE, 100);
        Runnable user2 = () -> machine.orderCoffee(CoffeeType.ESPRESSO, 50);

        new Thread(user1).start();
        new Thread(user2).start();
    }
}