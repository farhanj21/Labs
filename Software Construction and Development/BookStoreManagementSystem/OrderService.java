import java.sql.*;
import java.util.List;

public class OrderService {
    private OrderDAO orderDAO;

    public OrderService(Connection connection) {

        this.orderDAO = new OrderDAO(connection);
    }

    public void addOrder(Order order) {
        try {
            orderDAO.addOrder(order);
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    public Order getOrderById(int id) {
        try {
            return orderDAO.getOrderById(id);
        } catch (SQLException e) {
            e.printStackTrace();
            return null;
        }
    }

    public List<Order> getAllOrders() {
        try {
            return orderDAO.getAllOrders();
        } catch (SQLException e) {
            e.printStackTrace();
            return null;
        }
    }

    public void updateOrder(Order order) {
        try {
            orderDAO.updateOrder(order);
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    public void deleteOrder(int orderId) {
        try {
            orderDAO.deleteOrder(orderId);
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }
}
