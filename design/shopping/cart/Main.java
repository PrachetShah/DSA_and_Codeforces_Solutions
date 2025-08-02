public class Main {
    public static void main(String[] args) {
        Cart cart = new Cart();
        cart.addProduct(new Product("Postcard Sorter", "postcard", 10));
        cart.addCoupon(new PercentageOffNextItemCoupon(10)); // 10% off next
        cart.addProduct(new Product("Stationery Organizer", "stationery", 20));

        System.out.println("Cart Total: $" + cart.calculateTotal()); // should be $28
        cart.printCart();

        // Test Complex Example
        System.out.println("\n--- Complex Example ---");
        Cart cart2 = new Cart();
        cart2.addProduct(new Product("Postcard Sorter", "postcard", 10));
        cart2.addCoupon(new FixedAmountNthItemCoupon(2, "postcard", 2));
        cart2.addCoupon(new PercentageOffAllItemsCoupon(25));
        cart2.addCoupon(new PercentageOffNextItemCoupon(10));
        cart2.addProduct(new Product("Postcard Sorter", "postcard", 10));

        System.out.println("Cart Total: $" + cart2.calculateTotal()); // should be $12.90
        cart2.printCart();
    }
}

