import java.util.ArrayList;
import java.util.List;

public class ParkingFloor {
    private String name;
    private List<ParkingSpot> spots;

    public ParkingFloor(String name){
        this.name = name;
        spots = new ArrayList<>();
    }

    public String getName(){
        return this.name;
    }

    public void addSpot(ParkingSpot spot){
        this.spots.add(spot);
    }

    public ParkingSpot getAvailableSpot(Class<?> vehicleType){
        for(ParkingSpot spot: spots){
            if(spot.isAvailable() && ((vehicleType == Car.class && spot instanceof CarSpot) || (vehicleType == Bike.class && spot instanceof BikeSpot))){
                return spot;
            }
        }
        return null;
    }
}
