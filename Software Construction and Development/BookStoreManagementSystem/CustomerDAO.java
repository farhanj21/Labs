import java.sql.*;
import java.util.ArrayList;
import java.util.List;

public class CustomerDAO {
    private Connection connection;

    public CustomerDAO(Connection connection) {
        this.connection = connection;
    }


    public void addCustomer(Customer customer) throws SQLException {
        PreparedStatement ps = connection.prepareStatement("INSERT INTO customers(first_name, last_name, email, user_id) VALUES (?, ?, ?, ?)");
        ps.setString(1, customer.getFirstName());
        ps.setString(2, customer.getLastName());
        ps.setString(3, customer.getEmail());
        ps.setInt(4, customer.getUserId());
        ps.executeUpdate();
    }


    public Customer getCustomerById(int id) throws SQLException {
        PreparedStatement ps = connection.prepareStatement("SELECT * FROM customers WHERE customer_id = ?");
        ps.setInt(1, id);
        ResultSet rs = ps.executeQuery();
        if (rs.next()) {
            return new Customer(rs.getInt("customer_id"), rs.getString("first_name"), rs.getString("last_name"), rs.getString("email"), rs.getInt("user_id"));
        }
        return null;
    }

    public List<Customer> getAllCustomers() throws SQLException {
        List<Customer> customers = new ArrayList<>();
        Statement st = connection.createStatement();
        ResultSet rs = st.executeQuery("SELECT * FROM customers");
        while (rs.next()) {
            customers.add(new Customer(rs.getInt("customer_id"), rs.getString("first_name"), rs.getString("last_name"), rs.getString("email"), rs.getInt("user_id")));
        }
        return customers;
    }


    public void updateCustomer(Customer customer) throws SQLException {
        PreparedStatement ps = connection.prepareStatement("UPDATE customers SET first_name=?, last_name=?, email=?, user_id=? WHERE customer_id=?");
        ps.setString(1, customer.getFirstName());
        ps.setString(2, customer.getLastName());
        ps.setString(3, customer.getEmail());
        ps.setInt(4, customer.getUserId());
        ps.setInt(5, customer.getCustomerId());
        ps.executeUpdate();
    }


    public void deleteCustomer(int customerId) throws SQLException {
        PreparedStatement ps = connection.prepareStatement("DELETE FROM customers WHERE customer_id=?");
        ps.setInt(1, customerId);
        ps.executeUpdate();
    }
    public boolean doesUserIdExist(int userId) throws SQLException {
        PreparedStatement ps = connection.prepareStatement("SELECT COUNT(*) FROM users WHERE user_id = ?");
        ps.setInt(1, userId);
        ResultSet rs = ps.executeQuery();
        if (rs.next()) {
            return rs.getInt(1) > 0;
        }
        return false;
    }

}

class Customer {
    private int customerId;
    private String firstName;
    private String lastName;
    private String email;
    private int userId;


    public Customer() {}

    public Customer(int customerId, String firstName, String lastName, String email, int userId) {
        this.customerId = customerId;
        this.firstName = firstName;
        this.lastName = lastName;
        this.email = email;
        this.userId = userId;
    }

    public int getCustomerId() {
        return customerId;
    }

    public void setCustomerId(int customerId) {
        this.customerId = customerId;
    }

    public String getFirstName() {
        return firstName;
    }

    public void setFirstName(String firstName) {
        this.firstName = firstName;
    }

    public String getLastName() {
        return lastName;
    }

    public void setLastName(String lastName) {
        this.lastName = lastName;
    }

    public String getEmail() {
        return email;
    }

    public void setEmail(String email) {
        this.email = email;
    }

    public int getUserId() {
        return userId;
    }

    public void setUserId(int userId) {
        this.userId = userId;
    }
}
