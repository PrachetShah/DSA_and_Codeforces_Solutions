public class Product {
    private final String name;
    private final String type;
    private final double basePrice;
    private double finalPrice;

    public Product(String name, String type, double price) {
        this.name = name;
        this.type = type;
        this.basePrice = price;
        this.finalPrice = price;
    }

    public String getName() { return name; }
    public String getType() { return type; }
    public double getBasePrice() { return basePrice; }
    public double getFinalPrice() { return finalPrice; }
    public void setFinalPrice(double price) { this.finalPrice = price; }

    @Override
    public String toString() {
        return name + " | $" + finalPrice;
    }
}