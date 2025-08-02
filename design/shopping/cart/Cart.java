import java.util.ArrayList;
import java.util.List;

class Cart {
    private final List<Product> products = new ArrayList<>();
    private final List<Coupon> coupons = new ArrayList<>();

    public void addProduct(Product p) {
        products.add(p);
    }

    public void addCoupon(Coupon c) {
        coupons.add(c);
    }

    public double calculateTotal() {
        // Reset final prices to base
        for (Product p : products) {
            p.setFinalPrice(p.getBasePrice());
        }

        // Apply coupons in order
        for (Coupon c : coupons) {
            c.apply(products);
        }

        double total = 0;
        for (Product p : products) {
            total += p.getFinalPrice();
        }

        return total;
    }

    public void printCart() {
        for (Product p : products) {
            System.out.println(p);
        }
    }
}
