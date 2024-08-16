import javax.sql.*;
import javax.swing.*;
import javax.swing.table.DefaultTableModel;
import java.awt.*;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.util.List;

public class LibraryGUI{
    private JFrame frame;
    private BookService bookService;
    private CustomerService customerService;
    private OrderService orderService;
    public LibraryGUI(boolean isAdmin, Connection connection){

        bookService = new BookService(connection);
        customerService = new CustomerService(connection);
        orderService = new OrderService(connection);


        frame = new JFrame("BookStore Management System");

        JButton addCustomer = new JButton("Add Customer");
        addCustomer.addActionListener(e -> new AddCustomerScreen(customerService));

        JButton addBook = new JButton("Add Book");
        addBook.addActionListener(e -> new AddBookScreen(bookService));

        JButton placeOrder= new JButton("Place Order");
        placeOrder.addActionListener(e -> new PlaceOrderScreen(orderService));

        JButton showOrder = new JButton("Show Orders");
        showOrder.addActionListener(e -> new ShowOrdersScreen(orderService));

        JButton browseBooks = new JButton("Browse Books");
        browseBooks.addActionListener(e -> new BrowseBooksScreen(bookService));

        JButton manageInventoryAndCustomers = new JButton("Manage Inventory & Customers");
        manageInventoryAndCustomers.addActionListener(e -> new ManageInventoryAndCustomersScreen(bookService, customerService));

        JPanel panel = new JPanel();
        if (isAdmin){
        panel.add(addCustomer);
        panel.add(addBook);
        panel.add(showOrder);
        panel.add(manageInventoryAndCustomers);
        } else {
            panel.add(placeOrder);
            panel.add(browseBooks);
        }

        frame.add(panel);
        frame.setSize(400,200);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.pack();
        frame.setVisible(true);
    }


    public static void main(String args[]) throws SQLException{
        try{
            Connection connection = DriverManager.getConnection("jdbc:mysql://localhost:3306/library","root","12345678");
        } catch (SQLException ex){
            ex.printStackTrace();
        }
    }
}
class AddCustomerScreen{
    private JFrame frame;
    private CustomerService customerService;
    public AddCustomerScreen(CustomerService customerService){
        this.customerService = customerService;
        frame = new JFrame("Add Customer");

        JPanel panel = new JPanel();
        panel.setLayout(new GridLayout(5, 2));

        JLabel firstName = new JLabel("First Name");
        JTextField firstNameField = new JTextField();

        JLabel lastName = new JLabel("Last Name");
        JTextField lastNameField = new JTextField();

        JLabel email = new JLabel("Email");
        JTextField emailField = new JTextField();

        JLabel userIdLabel = new JLabel("User ID");
        JTextField userIdField = new JTextField();

        JButton submit = new JButton("Add Customer");
        submit.addActionListener(e -> {
            int user_id = Integer.parseInt(userIdField.getText());
            if(customerService.doesUserIdExist(user_id)) {
              JOptionPane.showMessageDialog(frame,"User with this user_id exists");
            }else {
                try {
                    String first_name = firstNameField.getText();
                    String last_name = lastNameField.getText();
                    String email_add = emailField.getText();
                    user_id = Integer.parseInt(userIdField.getText());

                    Customer customer = new Customer(0, first_name, last_name, email_add, user_id);
                    customerService.addCustomer(customer);
                    JOptionPane.showMessageDialog(frame,"Customer added Successfully");
                    frame.dispose();
                }catch(Exception ex){
                    ex.printStackTrace();
                }
            }

        });
        panel.add(firstName);
        panel.add(firstNameField);
        panel.add(lastName);
        panel.add(lastNameField);
        panel.add(email);
        panel.add(emailField);
        panel.add(userIdLabel);
        panel.add(userIdField);
        panel.add(submit);

        frame.add(panel);
        frame.pack();
        frame.setVisible(true);
    }
}
class AddBookScreen{
    public JFrame frame;
    private BookService bookService;
    public AddBookScreen(BookService bookService){
            this.bookService=bookService;
            frame = new JFrame("Add to Cart");

            JPanel panel = new JPanel();
            panel.setLayout(new GridLayout(5,2));

            JLabel title = new JLabel("Title");
            JTextField titleField = new JTextField();

            JLabel author = new JLabel("Author");
            JTextField authorField = new JTextField();

            JLabel price = new JLabel("Price");
            JTextField priceField = new JTextField();

            JLabel inventory = new JLabel("Inventory Count");
            JTextField inventoryField = new JTextField();

            JButton addBook = new JButton("Add Book");
            addBook.addActionListener(e -> {
                String bookTitle = titleField.getText();
                String authorTitle = authorField.getText();
                double priceText = Double.parseDouble(priceField.getText());
                int count = Integer.parseInt(inventoryField.getText());

                Book book = new Book(0,bookTitle,authorTitle,priceText,count);
                bookService.addBook(book);
                JOptionPane.showMessageDialog(frame,"Book added Successfully!");
                frame.dispose();


            });
        panel.add(title);
        panel.add(titleField);
        panel.add(author);
        panel.add(authorField);
        panel.add(price);
        panel.add(priceField);
        panel.add(inventory);
        panel.add(inventoryField);
        panel.add(new JLabel()); // filler
        panel.add(addBook);

        frame.add(panel);
        frame.pack();
        frame.setVisible(true);
    }
}
class PlaceOrderScreen{
    public JFrame frame;
    private  OrderService orderService;
    public PlaceOrderScreen(OrderService orderService){
            this.orderService=orderService;
            frame = new JFrame("Place Order");

            JPanel panel = new JPanel();
            panel.setLayout(new GridLayout(4,2));

            JLabel customer = new JLabel("Customer ID");
            JTextField customerField = new JTextField();

            JLabel orderDate = new JLabel("Order Date (YYYY-MM-DD");
            JTextField orderDateField = new JTextField();

            JLabel total = new JLabel("Total");
            JTextField totalField = new JTextField();

            JButton submit = new JButton("Place Order");
            submit.addActionListener(e -> {
                int customerId = Integer.parseInt(customerField.getText());
                String order = orderDateField.getText();
                double totalCount = Double.parseDouble(totalField.getText());

                Order order1 = new Order(0, customerId, order, totalCount);
                orderService.addOrder(order1);
                JOptionPane.showMessageDialog(frame,"Order placed successfully!");
                frame.dispose();
            });
        panel.add(customer);
        panel.add(customerField);
        panel.add(orderDate);
        panel.add(orderDateField);
        panel.add(total);
        panel.add(totalField);
        panel.add(new JLabel());
        panel.add(submit);

        frame.add(panel);
        frame.pack();
        frame.setVisible(true);
    }

}
class ShowOrdersScreen{
    private JFrame frame;
    private OrderService orderService;
    private  JTable orderTable;
    public ShowOrdersScreen(OrderService orderService){
        this.orderService=orderService;
        frame = new JFrame("Show Orders");

        List<Order>orders = orderService.getAllOrders();
        String[] columns = {"Order ID", "Customer ID","Order Date","Total"};
        Object [] [] data = new Object[orders.size()][4];
        int index =0;
        for (Order order:orders){
            data[index][0]=order.getOrderId();
            data[index][1]=order.getCustomerId();
            data[index][2]=order.getOrderDate();
            data[index][3]=order.getTotal();
            index++;
        }
        orderTable = new JTable(data,columns);
        JScrollPane scrollPane = new JScrollPane(orderTable);
        orderTable.setFillsViewportHeight(true);

        frame.setLayout(new BorderLayout());
        frame.add(scrollPane,BorderLayout.CENTER);
        frame.pack();
        frame.setVisible(true);

    }


}
class  BrowseBooksScreen{
        private JFrame frame;
        private BookService bookService;
        private JTable bookTable;
        private DefaultTableModel model;
        private JButton addToCart;
        private  List<Book> books;
        public BrowseBooksScreen(BookService bookService){
            this.bookService=bookService;
            frame = new JFrame("Browse Books");

            books = bookService.getAllBooks();
            String[] columns = {"Book ID", "Title", "Author", "Price", "Inventory Count"};
            model = new DefaultTableModel(columns, 0);
            for (Book book : books) {
                model.addRow(new Object[]{book.getBookId(), book.getTitle(), book.getAuthor(), book.getPrice(), book.getInventoryCount()});
            }
            bookTable = new JTable(model);
            JScrollPane scrollPane = new JScrollPane(bookTable);
            bookTable.setFillsViewportHeight(true);

            addToCart = new JButton("Add to Cart");
            addToCart.addActionListener(e -> {
                int selectedRow = bookTable.getSelectedRow();
                if (selectedRow != -1) {
                    Book selectedBook = books.get(selectedRow);
                    // TODO: Add selectedBook to the cart
                    JOptionPane.showMessageDialog(frame, "Book added to the cart!");
                }
            });

            frame.setLayout(new BorderLayout());
            frame.add(scrollPane, BorderLayout.CENTER);
            frame.add(addToCart, BorderLayout.SOUTH);
            frame.pack();
            frame.setVisible(true);
        }

}
class ManageInventoryAndCustomersScreen {
    private JFrame frame;
    private BookService bookService;
    private CustomerService customerService;
    private JTabbedPane tabbedPane;
    private JTable bookTable;
    private JTable customerTable;
    private DefaultTableModel bookModel;
    private DefaultTableModel customerModel;
    private List<Book> books;
    private List<Customer> customers;

    public ManageInventoryAndCustomersScreen(BookService bookService, CustomerService customerService) {
        this.bookService = bookService;
        this.customerService = customerService;
        frame = new JFrame("Manage Inventory and Customers");

        books = bookService.getAllBooks();
        customers = customerService.getAllCustomers();

        // Books Table
        String[] bookColumns = {"Book ID", "Title", "Author", "Price", "Inventory Count"};
        bookModel = new DefaultTableModel(bookColumns, 0);
        for (Book book : books) {
            bookModel.addRow(new Object[]{book.getBookId(), book.getTitle(), book.getAuthor(), book.getPrice(), book.getInventoryCount()});
        }
        bookTable = new JTable(bookModel);

        // Customers Table
        String[] customerColumns = {"Customer ID", "First Name", "Last Name", "Email"};
        customerModel = new DefaultTableModel(customerColumns, 0);
        for (Customer customer : customers) {
            customerModel.addRow(new Object[]{customer.getUserId(), customer.getFirstName(), customer.getLastName(), customer.getEmail()});
        }
        customerTable = new JTable(customerModel);

        tabbedPane = new JTabbedPane();
        tabbedPane.addTab("Books", new JScrollPane(bookTable));
        tabbedPane.addTab("Customers", new JScrollPane(customerTable));

        frame.setLayout(new BorderLayout());
        frame.add(tabbedPane, BorderLayout.CENTER);
        frame.pack();
        frame.setVisible(true);
    }
}

