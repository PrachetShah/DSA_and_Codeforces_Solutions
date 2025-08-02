import java.time.Duration;
import java.time.LocalDateTime;

public class Ticket {
    private static int counter = 1;
    private int ticketId;
    private LocalDateTime entryTime;
    private ParkingSpot spot;
    private Vehicle vehicle;

    public Ticket(ParkingSpot spot, Vehicle vechicle){
        this.ticketId = counter++;
        this.spot = spot;
        this.vehicle = vechicle;
        this.entryTime = LocalDateTime.now();
    }

    public int getId(){
        return this.ticketId;
    }

    public ParkingSpot getSpot(){
        return this.spot;
    }

    public long calculateFare(){
        LocalDateTime exitTime = LocalDateTime.now();
        Duration duration = Duration.between(exitTime, this.entryTime);
        return Math.max(duration.toHours(), 1)*20;
    }

    public Vehicle getVehicle() {
        return vehicle;
    }
}
