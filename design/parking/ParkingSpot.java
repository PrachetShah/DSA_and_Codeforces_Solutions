public class ParkingSpot {
    private int id;
    private boolean isOccupied = false;
    private Vehicle vehicle;

    public ParkingSpot(int id){
        this.id = id;
    }

    public boolean isAvailable(){
        return !this.isOccupied;
    }

    public void occupySpot(Vehicle vehicle){
        this.vehicle = vehicle;
        this.isOccupied = true;
    }

    public void emptySpot(){
        this.vehicle = null;
        this.isOccupied = false;
    }

    public int getId(){
        return this.id;
    }

    public Vehicle getVehicle() {
        return vehicle;
    }
}

class CarSpot extends ParkingSpot{
    public CarSpot(int id){
        super(id);
    }
}

class BikeSpot extends ParkingSpot{
    public BikeSpot(int id){
        super(id);
    }
}
