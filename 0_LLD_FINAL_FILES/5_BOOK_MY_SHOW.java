import java.util.*;

// =========================================
// ENUMS
// =========================================
enum SeatStatus { AVAILABLE, LOCKED, BOOKED; }


// =========================================
// ENTITIES (NO CIRCULAR DEPENDENCY)
// =========================================
class Movie {
    int id;
    String name;
}

class Seat {
    int id;
    SeatStatus status = SeatStatus.AVAILABLE;
}

class Screen {
    int id;
    List<Seat> seats;
}

class Show {
    int id;
    Movie movie;
    Screen screen;
    String startTime;
}

class Theatre {
    int id;
    String name;
    String city;
    List<Show> shows = new ArrayList<>();
}

class User {
    int id;
    String name;
}


// =========================================
// SEAT LOCK MANAGER (Singleton + Expiry)
// =========================================
class SeatLockManager {

    private static SeatLockManager instance;
    private SeatLockManager() {}

    public static SeatLockManager getInstance() {
        if (instance == null) instance = new SeatLockManager();
        return instance;
    }

    private final long EXPIRY = 30000; // 30 sec lock
    private Map<Integer, Long> lockedSeats = new HashMap<>();

    public synchronized boolean lock(Seat seat) {
        long now = System.currentTimeMillis();

        if (lockedSeats.containsKey(seat.id)) {
            long lockedAt = lockedSeats.get(seat.id);
            if (lockedAt + EXPIRY > now)
                return false; // seat still locked
        }

        lockedSeats.put(seat.id, now);
        seat.status = SeatStatus.LOCKED;
        return true;
    }

    public synchronized void unlock(Seat seat) {
        lockedSeats.remove(seat.id);
        seat.status = SeatStatus.AVAILABLE;
    }
}


// =========================================
// PAYMENT (Strategy + Factory)
// =========================================
interface PaymentStrategy {
    boolean pay(double amount);
}

class UpiPayment implements PaymentStrategy {
    public boolean pay(double amount) {
        System.out.println("PAID via UPI: Rs " + amount);
        return true;
    }
}

class CardPayment implements PaymentStrategy {
    public boolean pay(double amount) {
        System.out.println("PAID via CARD: Rs " + amount);
        return true;
    }
}

class PaymentFactory {
    public static PaymentStrategy get(String mode) {
        return switch (mode) {
            case "UPI" -> new UpiPayment();
            case "CARD" -> new CardPayment();
            default -> throw new RuntimeException("Invalid payment mode");
        };
    }
}


// =========================================
// BOOKING SERVICE (Singleton + Clear Flow)
// =========================================
class BookingService {

    private static BookingService instance;
    private BookingService() {}

    public static BookingService getInstance() {
        if (instance == null) instance = new BookingService();
        return instance;
    }

    SeatLockManager locker = SeatLockManager.getInstance();

    // Search movies in city
    List<Movie> searchMovies(List<Theatre> theatres, String city) {
        Set<Movie> results = new HashSet<>();
        for (Theatre t : theatres) {
            if (t.city.equalsIgnoreCase(city)) {
                for (Show s : t.shows)
                    results.add(s.movie);
            }
        }
        return new ArrayList<>(results);
    }

    // Get shows for a theatre
    List<Show> searchShows(Theatre theatre) {
        return theatre.shows;
    }

    // View seat layout
    void showSeatLayout(Show show) {
        System.out.println("\n-- Seat Layout --");
        for (Seat s : show.screen.seats) {
            System.out.println("Seat " + s.id + " -> " + s.status);
        }
    }

    // Booking logic
    void book(User user, Show show, List<Seat> seats, PaymentStrategy payment) {

        // 1. Lock seats
        for (Seat s : seats) {
            boolean ok = locker.lock(s);
            if (!ok)
                throw new RuntimeException("Seat " + s.id + " is locked by someone else");
        }
        System.out.println("[INFO] Seats locked: " + seats.size());

        // 2. Payment
        boolean paid = payment.pay(200);

        // 3. Confirm / release seats
        if (paid) {
            for (Seat s : seats) s.status = SeatStatus.BOOKED;
            System.out.println("[SUCCESS] Booking Confirmed");
        } else {
            for (Seat s : seats) locker.unlock(s);
            System.out.println("[FAILED] Payment Failed. Seats Released.");
        }
    }
}


// =========================================
// MAIN DEMO
// =========================================
public class Main {

    public static void main(String[] args) {

        // ------- Setup Data -------
        Movie m = new Movie();
        m.id = 1;
        m.name = "Interstellar";

        Seat s1 = new Seat(); s1.id = 1;
        Seat s2 = new Seat(); s2.id = 2;

        Screen screen = new Screen();
        screen.id = 101;
        screen.seats = Arrays.asList(s1, s2);

        Show show = new Show();
        show.id = 1001;
        show.movie = m;
        show.screen = screen;
        show.startTime = "6:00 PM";

        Theatre t = new Theatre();
        t.id = 501;
        t.name = "IMAX";
        t.city = "Mumbai";
        t.shows = Arrays.asList(show);

        User user = new User();
        user.id = 1;
        user.name = "Aditya";

        BookingService bs = BookingService.getInstance();


        // ------- FLOW -------
        System.out.println("Movies in Mumbai:");
        System.out.println(bs.searchMovies(Arrays.asList(t), "Mumbai"));

        System.out.println("\nShows in IMAX:");
        for (Show s : bs.searchShows(t)) {
            System.out.println("Show " + s.id + " : " + s.movie.name + " at " + s.startTime);
        }

        System.out.println("\nBefore Booking:");
        bs.showSeatLayout(show);

        PaymentStrategy payment = PaymentFactory.get("UPI");

        bs.book(user, show, Arrays.asList(s1, s2), payment);

        System.out.println("\nAfter Booking:");
        bs.showSeatLayout(show);
    }
}
