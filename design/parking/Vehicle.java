public abstract class Vehicle {
    private String plateNumber;
    public Vehicle(String plateNumber){
        this.plateNumber = plateNumber;
    }
    public String getPlateNumber(){
        return this.plateNumber;
    }
}

class Car extends Vehicle{
    public Car(String plateNumber){
        super(plateNumber);
    }
}

class Bike extends Vehicle{
    public Bike(String plateNumber){
        super(plateNumber);
    }
}