import java.util.ArrayList;
import java.util.List;

public class ParkingLot {
    private List<ParkingFloor> floors;

    public ParkingLot(){
        this.floors = new ArrayList<>();
    }

    public void addFloor(ParkingFloor floor){
        floors.add(floor);
    }

    public Ticket parkVehicle(Vehicle vehicle){
        for(ParkingFloor floor: floors){
            ParkingSpot spot = floor.getAvailableSpot(vehicle.getClass());
            if(spot != null && spot.isAvailable()){
                spot.occupySpot(vehicle);
                System.out.println("Parked " + vehicle.getPlateNumber() + " at " + spot.getId() + " on " + floor.getName());
                return new Ticket(spot, vehicle);
            }
        }
        throw new RuntimeException("All Parking Spaces are Full...");
    }

    public long unparkVehicle(Ticket ticket){
        long fare = ticket.calculateFare();
        ParkingSpot spot = ticket.getSpot();
        spot.emptySpot();
        return fare;
    }

    public static void main(String[] args) {
        ParkingLot p = new ParkingLot();

        ParkingFloor one = new ParkingFloor("floor 1");
        ParkingFloor two = new ParkingFloor("floor 2");
        ParkingFloor three = new ParkingFloor("floor 3");

        one.addSpot(new CarSpot(1));
        one.addSpot(new CarSpot(2));
        two.addSpot(new BikeSpot(1));
        three.addSpot(new CarSpot(3));

        Vehicle v1 = new Car("innova");
        Vehicle v2 = new Car("merc");
        Vehicle v3 = new Car("honda");
        Vehicle v4 = new Bike("suzuki");
        Vehicle v5 = new Car("bmw");

        p.addFloor(one);
        p.addFloor(two);
        p.addFloor(three);

        p.parkVehicle(v1);
        p.parkVehicle(v2);
        p.parkVehicle(v3);
        p.parkVehicle(v4);
        try{
            p.parkVehicle(v5);
        }catch(Exception e){
            System.out.println(e.getMessage());
        }
    }
}
