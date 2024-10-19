package vendingmachine;
import java.util.HashMap;

public class VendingMachine {

    private String config;
    HashMap<String, Product> products = new HashMap<String, Product>();

    public readConfig() {
        config = new helpers.YMLReader().config("config.yml");
        return config;
    }
    public Product getProduct(String name) {
        return products.get(name);
    }
    public void addProduct(Product product) {
        products.put(product.getName(), product);
    }
    public void removeProduct(String name) {
        products.remove(name);
    }
    public void updateProductQuantity(String name, int quantity) {
        Product product = products.get(name);
        product.quantity = quantity;
    }

}
