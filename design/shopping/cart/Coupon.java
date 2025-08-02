import java.util.List;

public interface Coupon {
    void apply(List<Product> products);
}

// 1. Percentage off each individual item
class PercentageOffAllItemsCoupon implements Coupon {
    private final double percentage;

    public PercentageOffAllItemsCoupon(double percentage) {
        this.percentage = percentage;
    }

    public void apply(List<Product> products) {
        for (Product p : products) {
            double price = p.getFinalPrice();
            p.setFinalPrice(price * (1 - percentage / 100.0));
        }
    }
}

// 2. Percentage off next product
class PercentageOffNextItemCoupon implements Coupon {
    private final double percentage;

    public PercentageOffNextItemCoupon(double percentage) {
        this.percentage = percentage;
    }

    public void apply(List<Product> products) {
        for (Product p : products) {
            p.setFinalPrice(p.getFinalPrice() * (1 - percentage / 100.0));
            break; // Only apply to next available item
        }
    }
}

// 3. Fixed discount on Nth item of type T
class FixedAmountNthItemCoupon implements Coupon {
    private final double discount;
    private final String targetType;
    private final int nth;

    public FixedAmountNthItemCoupon(double discount, String targetType, int nth) {
        this.discount = discount;
        this.targetType = targetType;
        this.nth = nth;
    }

    public void apply(List<Product> products) {
        int count = 0;
        for (Product p : products) {
            if (p.getType().equalsIgnoreCase(targetType)) {
                count++;
                if (count == nth) {
                    double price = p.getFinalPrice();
                    p.setFinalPrice(Math.max(0.0, price - discount));
                    break;
                }
            }
        }
    }
}
