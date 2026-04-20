import java.util.*;
import java.util.concurrent.PriorityBlockingQueue;

// ENUMS
enum Direction {
    UP, DOWN, IDLE
}

enum State {
    MOVING, IDLE
}

// REQUEST
class Request {
    int source;
    int destination;
    Direction direction;

    Request(int s, int d) {
        this.source = s;
        this.destination = d;
        this.direction = d > s ? Direction.UP : Direction.DOWN;
    }
}

// STRATEGY INTERFACE
interface SchedulerStrategy {
    Elevator selectElevator(List<Elevator> elevators, Request req);
}

// SIMPLE NEAREST ELEVATOR STRATEGY
class NearestElevatorStrategy implements SchedulerStrategy {

    @Override
    public Elevator selectElevator(List<Elevator> elevators, Request req) {
        Elevator best = null;
        int minDistance = Integer.MAX_VALUE;

        for (Elevator e : elevators) {
            int dist = Math.abs(e.currentFloor - req.source);

            if (dist < minDistance && e.canTakeRequest(req)) {
                minDistance = dist;
                best = e;
            }
        }
        return best;
    }
}

// ELEVATOR
class Elevator {
    int id;
    int capacity;
    int currentFloor;
    Direction direction;
    State state;

    // requests
    PriorityQueue<Integer> upQueue = new PriorityQueue<>();
    PriorityQueue<Integer> downQueue = new PriorityQueue<>(Collections.reverseOrder());

    Elevator(int id, int capacity) {
        this.id = id;
        this.capacity = capacity;
        this.currentFloor = 0;
        this.direction = Direction.IDLE;
        this.state = State.IDLE;
    }

    // check if elevator can take request
    public boolean canTakeRequest(Request req) {
        return true; // simplified (can extend for capacity/direction check)
    }

    public synchronized void addRequest(Request req) {
        if (req.direction == Direction.UP) {
            upQueue.offer(req.destination);
        } else {
            downQueue.offer(req.destination);
        }
    }

    public synchronized void move() {
        if (direction == Direction.UP) {
            if (!upQueue.isEmpty()) {
                currentFloor = upQueue.poll();
            } else {
                direction = Direction.DOWN;
            }
        } else if (direction == Direction.DOWN) {
            if (!downQueue.isEmpty()) {
                currentFloor = downQueue.poll();
            } else {
                direction = Direction.UP;
            }
        } else {
            // idle → pick direction
            if (!upQueue.isEmpty()) direction = Direction.UP;
            else if (!downQueue.isEmpty()) direction = Direction.DOWN;
        }

        System.out.println("Elevator " + id + " at floor " + currentFloor);
    }
}

// CONTROLLER
class ElevatorController {
    List<Elevator> elevators;
    SchedulerStrategy strategy;

    ElevatorController(int n, int capacity) {
        elevators = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            elevators.add(new Elevator(i, capacity));
        }
        strategy = new NearestElevatorStrategy();
    }

    public void requestElevator(int source, int destination) {
        Request req = new Request(source, destination);

        Elevator elevator = strategy.selectElevator(elevators, req);

        if (elevator != null) {
            elevator.addRequest(req);
        }
    }

    public void startSystem() {
        // simulate threads
        for (Elevator e : elevators) {
            new Thread(() -> {
                while (true) {
                    e.move();
                    try {
                        Thread.sleep(1000);
                    } catch (Exception ex) {}
                }
            }).start();
        }
    }
}

// MAIN
public class ElevatorSystem {
    public static void main(String[] args) {
        ElevatorController controller = new ElevatorController(3, 10);

        controller.startSystem();

        controller.requestElevator(0, 5);
        controller.requestElevator(2, 8);
        controller.requestElevator(7, 1);
    }
}