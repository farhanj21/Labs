import java.sql.SQLException;
import java.util.List;
import java.sql.Connection;

public class CustomerService {
    private CustomerDAO customerDAO;

    public CustomerService(Connection connection) {

        this.customerDAO = new CustomerDAO(connection);
    }
    public boolean doesUserIdExist(int userId) {
        try {
            return customerDAO.doesUserIdExist(userId);
        } catch (SQLException e) {
            e.printStackTrace();
            return false; // or handle this exception in another appropriate manner
        }
    }


    public void addCustomer(Customer customer) {
        try {
            customerDAO.addCustomer(customer);
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    public Customer getCustomerById(int id) {
        try {
            return customerDAO.getCustomerById(id);
        } catch (SQLException e) {
            e.printStackTrace();
            return null;
        }
    }

    public List<Customer> getAllCustomers() {
        try {
            return customerDAO.getAllCustomers();
        } catch (SQLException e) {
            e.printStackTrace();
            return null;
        }
    }

    public void updateCustomer(Customer customer) {
        try {
            customerDAO.updateCustomer(customer);
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    public void deleteCustomer(int customerId) {
        try {
            customerDAO.deleteCustomer(customerId);
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }
}
