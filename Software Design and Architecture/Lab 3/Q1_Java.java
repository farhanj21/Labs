package q1;


public class Website {

    public static void main(String[] args) {
    }

    public void confirmation() {
    }

    public void displayConfirmation() {
    }

    public void processPayment() {
    }
}

class User {

    private String name;

    private String password;

    private String address;

    private Payment paymentMethod;

    public void login() {
    }

    public String enterAddress(String address) {
        throw new UnsupportedOperationException("Not supported yet.");
    }

    public String enterPaymentInfo(String paymentMethod) {
        throw new UnsupportedOperationException("Not supported yet.");
    }

    public void confirmOrder() {
    }

    public void addtoCart() {
    }

    public void removefromCart() {
    }
}

enum Payment 
{

    Cash, Card
}


class Product 
{

    private String name;

    private int quantity;

    private Double price;

    public int increaseQuantity(int quantity) {
        throw new UnsupportedOperationException("Not supported yet.");
    }

    public void addtoCart() {
    }

    public void removefromCart() {
    }
}

class Cart {

    private int quantity;

    private int total;

    public int total(int quantity, int total) {
        throw new UnsupportedOperationException("Not supported yet.");
    }

    public void completeOrder() {
    }
}


