import java.sql.*;
import java.util.ArrayList;
import java.util.List;

public class OrderDAO {
    private Connection connection;

    public OrderDAO(Connection connection) {
        this.connection = connection;
    }

    // CREATE
    public void addOrder(Order order) throws SQLException {
        PreparedStatement ps = connection.prepareStatement("INSERT INTO orders(customer_id, order_date, total) VALUES (?, ?, ?)");
        ps.setInt(1, order.getCustomerId());
        ps.setString(2, order.getOrderDate());
        ps.setDouble(3, order.getTotal());
        ps.executeUpdate();
    }

    // READ
    public Order getOrderById(int id) throws SQLException {
        PreparedStatement ps = connection.prepareStatement("SELECT * FROM orders WHERE order_id = ?");
        ps.setInt(1, id);
        ResultSet rs = ps.executeQuery();
        if (rs.next()) {
            return new Order(rs.getInt("order_id"), rs.getInt("customer_id"), rs.getString("order_date"), rs.getDouble("total"));
        }
        return null;
    }

    public List<Order> getAllOrders() throws SQLException {
        List<Order> orders = new ArrayList<>();
        Statement st = connection.createStatement();
        ResultSet rs = st.executeQuery("SELECT * FROM orders");
        while (rs.next()) {
            orders.add(new Order(rs.getInt("order_id"), rs.getInt("customer_id"), rs.getString("order_date"), rs.getDouble("total")));
        }
        return orders;
    }

    // UPDATE
    public void updateOrder(Order order) throws SQLException {
        PreparedStatement ps = connection.prepareStatement("UPDATE orders SET customer_id=?, order_date=?, total=? WHERE order_id=?");
        ps.setInt(1, order.getCustomerId());
        ps.setString(2, order.getOrderDate());
        ps.setDouble(3, order.getTotal());
        ps.setInt(4, order.getOrderId());
        ps.executeUpdate();
    }

    // DELETE
    public void deleteOrder(int orderId) throws SQLException {
        PreparedStatement ps = connection.prepareStatement("DELETE FROM orders WHERE order_id=?");
        ps.setInt(1, orderId);
        ps.executeUpdate();
    }
}
class Order {
    private int orderId;
    private int customerId;
    private String orderDate;
    private double total;

    public Order(int orderId, int customerId, String orderDate, double total) {
        this.orderId = orderId;
        this.customerId = customerId;
        this.orderDate = orderDate;
        this.total = total;
    }

    // Getters and Setters
    public int getOrderId() {
        return orderId;
    }

    public void setOrderId(int orderId) {
        this.orderId = orderId;
    }

    public int getCustomerId() {
        return customerId;
    }

    public void setCustomerId(int customerId) {
        this.customerId = customerId;
    }

    public String getOrderDate() {
        return orderDate;
    }

    public void setOrderDate(String orderDate) {
        this.orderDate = orderDate;
    }

    public double getTotal() {
        return total;
    }

    public void setTotal(double total) {
        this.total = total;
    }
}
