/*
 * ======================================================
 *                  PARKING LOT SYSTEM (LLD)
 * ======================================================
 *
 * Designed for backend system design interviews
 * Clean layering (Controller → Service → Entities)
 * Extensible, SOLID, and easy to integrate with Spring
 */

import java.time.LocalDateTime;
import java.time.temporal.ChronoUnit;
import java.util.*;
import java.util.concurrent.ConcurrentHashMap;

// ======================================================
// ENUMS
// ======================================================

enum VehicleType {
    CAR, BIKE, TRUCK, VAN
}

enum SpotType {
    COMPACT, LARGE, HANDICAPPED, MOTORBIKE
}

// ======================================================
// VEHICLE
// ======================================================

class Vehicle {
    private final String vehicleId;
    private final VehicleType type;

    public Vehicle(String vehicleId, VehicleType type) {
        this.vehicleId = vehicleId;
        this.type = type;
    }

    public VehicleType getType() { return type; }
    public String getVehicleId() { return vehicleId; }
}

// ======================================================
// PARKING SPOTS
// ======================================================

abstract class ParkingSpot {
    protected final String spotId;
    protected final SpotType type;
    protected boolean isAvailable = true;
    protected Vehicle vehicle;

    public ParkingSpot(String spotId, SpotType type) {
        this.spotId = spotId;
        this.type = type;
    }

    public boolean park(Vehicle v) {
        if (!isAvailable) return false;
        this.vehicle = v;
        this.isAvailable = false;
        return true;
    }

    public void freeSpot() {
        this.vehicle = null;
        this.isAvailable = true;
    }

    public boolean isAvailable() { return isAvailable; }
    public SpotType getType() { return type; }
    public String getSpotId() { return spotId; }
}

class CompactSpot extends ParkingSpot {
    public CompactSpot(String id) { super(id, SpotType.COMPACT); }
}
class LargeSpot extends ParkingSpot {
    public LargeSpot(String id) { super(id, SpotType.LARGE); }
}
class MotorbikeSpot extends ParkingSpot {
    public MotorbikeSpot(String id) { super(id, SpotType.MOTORBIKE); }
}

// ======================================================
// TICKET
// ======================================================

class Ticket {
    private final String ticketId;
    private final Vehicle vehicle;
    private final ParkingSpot spot;
    private final LocalDateTime entryTime;
    private LocalDateTime exitTime;
    private double totalPrice;

    public Ticket(Vehicle v, ParkingSpot s) {
        this.ticketId = UUID.randomUUID().toString();
        this.vehicle = v;
        this.spot = s;
        this.entryTime = LocalDateTime.now();
    }

    public void closeTicket(double price) {
        this.exitTime = LocalDateTime.now();
        this.totalPrice = price;
    }

    public String getTicketId() { return ticketId; }
    public Vehicle getVehicle() { return vehicle; }
    public ParkingSpot getSpot() { return spot; }
    public LocalDateTime getEntryTime() { return entryTime; }
    public double getTotalPrice() { return totalPrice; }
}

// ======================================================
// STRATEGIES
// ======================================================

interface PricingStrategy {
    double calculate(Ticket ticket);
}

class DefaultPricingStrategy implements PricingStrategy {
    private static final Map<VehicleType, Double> RATE_PER_HOUR = Map.of(
        VehicleType.CAR, 30.0,
        VehicleType.BIKE, 10.0,
        VehicleType.TRUCK, 50.0,
        VehicleType.VAN, 40.0
    );

    @Override
    public double calculate(Ticket ticket) {
        long hours = Math.max(1,
            ChronoUnit.HOURS.between(ticket.getEntryTime(), LocalDateTime.now()));
        return RATE_PER_HOUR.get(ticket.getVehicle().getType()) * hours;
    }
}

interface SpotAssignmentStrategy {
    ParkingSpot findSpot(List<ParkingSpot> spots, Vehicle vehicle);
}

class NearestAvailableSpotStrategy implements SpotAssignmentStrategy {
    private static final Map<VehicleType, Set<SpotType>> allowed = Map.of(
        VehicleType.CAR, Set.of(SpotType.COMPACT, SpotType.LARGE),
        VehicleType.BIKE, Set.of(SpotType.MOTORBIKE),
        VehicleType.TRUCK, Set.of(SpotType.LARGE),
        VehicleType.VAN, Set.of(SpotType.LARGE)
    );

    @Override
    public ParkingSpot findSpot(List<ParkingSpot> spots, Vehicle v) {
        return spots.stream()
            .filter(spot -> spot.isAvailable()
                && allowed.get(v.getType()).contains(spot.getType()))
            .findFirst()
            .orElse(null);
    }
}

// ======================================================
// FLOOR
// ======================================================

class Floor {
    private final int floorId;
    private final List<ParkingSpot> spots;

    public Floor(int id, List<ParkingSpot> spots) {
        this.floorId = id;
        this.spots = spots;
    }

    public List<ParkingSpot> getSpots() { return spots; }
    public int getFloorId() { return floorId; }
}

// ======================================================
// PARKING LOT (Core Service Layer)
// ======================================================

class ParkingLot {
    private final List<Floor> floors;
    private final PricingStrategy pricingStrategy;
    private final SpotAssignmentStrategy assignmentStrategy;
    private final Map<String, Ticket> activeTickets = new ConcurrentHashMap<>();

    public ParkingLot(List<Floor> floors, PricingStrategy pricing, SpotAssignmentStrategy strategy) {
        this.floors = floors;
        this.pricingStrategy = pricing;
        this.assignmentStrategy = strategy;
    }

    public Ticket parkVehicle(Vehicle v) {
        for (Floor floor : floors) {
            ParkingSpot spot = assignmentStrategy.findSpot(floor.getSpots(), v);
            if (spot != null && spot.park(v)) {
                Ticket t = new Ticket(v, spot);
                activeTickets.put(t.getTicketId(), t);
                System.out.println("Vehicle parked at floor " + floor.getFloorId() + ", spot " + spot.getSpotId());
                return t;
            }
        }
        System.out.println("No available spot for " + v.getType());
        return null;
    }

    public double unparkVehicle(String ticketId) {
        Ticket t = activeTickets.remove(ticketId);
        if (t == null) throw new IllegalArgumentException("Invalid ticket ID!");

        t.getSpot().freeSpot();
        double price = pricingStrategy.calculate(t);
        t.closeTicket(price);
        System.out.println("Vehicle " + t.getVehicle().getVehicleId() + " unparked. Price: ₹" + price);
        return price;
    }
}

// ======================================================
// PARKING LOT MANAGEMENT SERVICE (Facade Layer)
// ======================================================

class ParkingLotManagementService {
    private final ParkingLot parkingLot;

    // constructor “autowiring” dependencies (as in Spring)
    public ParkingLotManagementService() {
        List<ParkingSpot> floor1Spots = new ArrayList<>();
        floor1Spots.add(new CompactSpot("C1"));
        floor1Spots.add(new LargeSpot("L1"));
        floor1Spots.add(new MotorbikeSpot("M1"));

        Floor floor1 = new Floor(1, floor1Spots);

        PricingStrategy pricingStrategy = new DefaultPricingStrategy();
        SpotAssignmentStrategy spotStrategy = new NearestAvailableSpotStrategy();

        this.parkingLot = new ParkingLot(List.of(floor1), pricingStrategy, spotStrategy);
    }

    public Ticket parkVehicle(Vehicle vehicle) {
        return parkingLot.parkVehicle(vehicle);
    }

    public double unparkVehicle(String ticketId) {
        return parkingLot.unparkVehicle(ticketId);
    }
}

// ======================================================
// DRIVER
// ======================================================

public class ParkingLotSystem {
    public static void main(String[] args) throws InterruptedException {
        ParkingLotManagementService service = new ParkingLotManagementService();

        Vehicle car = new Vehicle("KA01AB1234", VehicleType.CAR);
        Ticket ticket = service.parkVehicle(car);

        Thread.sleep(2000);

        if (ticket != null) {
            service.unparkVehicle(ticket.getTicketId());
        }
    }
}
