import java.util.ArrayList;
import java.util.List;

interface Product {
    String getName();
    double getPrice();
}


class Book implements Product {
    private String name;
    private double price;

    public Book(String name, double price) {
        this.name = name;
        this.price = price;
    }

    @Override
    public String getName() {
        return name;
    }

    @Override
    public double getPrice() {
        return price;
    }
}

class Football implements Product {
    private String name;
    private double price;

    public Football(String name, double price) {
        this.name = name;
        this.price = price;
    }

    @Override
    public String getName() {
        return name;
    }

    @Override
    public double getPrice() {
        return price;
    }
}

class CompositeBox implements Product {
    private String name;
    private List<Product> products;

    public CompositeBox(String name) {
        this.name = name;
        products = new ArrayList<>();
    }

    public void addProduct(Product product) {
        products.add(product);
    }

    public void removeProduct(Product product) {
        products.remove(product);
    }
    
@Override
public String getName() {
    return name;
}

@Override
public double getPrice() {
    double totalPrice = 0;
    for (Product product : products) {
        totalPrice += product.getPrice();
    }
    return totalPrice;
}
}



