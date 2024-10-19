package vendingmachine;

public class Screen {
    public void screenFlow() {
        System.out.println("Welcome to the Vending Machine!");
        System.out.println("Please select an option:");
        System.out.println("1. Add products");
        System.out.println("2. Remove products");
        System.out.println("3. View products");
        System.out.println("4. Pay");
        System.out.println("5. Exit");
    }
    public void userInput() {
        System.out.println("Please enter your choice:");
    }
}
