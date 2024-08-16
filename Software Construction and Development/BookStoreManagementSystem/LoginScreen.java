import javax.swing.*;
import java.sql.*;
import  java.awt.*;
class LoginScreen {
    private JFrame frame;
    private JButton adminButton;
    private JButton customerButton;
    private JTextField usernameField;
    private JPasswordField passwordField;
    private  Connection connection;
    public LoginScreen() {
        frame = new JFrame("Login");

        JLabel titleLabel = new JLabel("Library Management System", SwingConstants.CENTER);
        titleLabel.setFont(new Font("Arial", Font.BOLD, 38));
        titleLabel.setForeground(Color.BLUE);

        JLabel welcome = new JLabel("Welcome to the System, Select your Role");
        welcome.setFont(new Font("Monospaced",Font.BOLD,24));
        welcome.setAlignmentX(5);

        adminButton = new JButton("Administrator");
        customerButton = new JButton("Customer");

        adminButton.setPreferredSize(new Dimension(40, 40));
        customerButton.setPreferredSize(new Dimension(40, 40));

        JLabel usernameLabel = new JLabel("Username");
        JLabel passwordLabel = new JLabel("Password");

        usernameField = new JTextField(20);
        passwordField = new JPasswordField(20);


        try {
            connection = DriverManager.getConnection("jdbc:mysql://localhost:3306/library", "root", "12345678");
        } catch (SQLException ex) {
            JOptionPane.showMessageDialog(frame, "Error connecting to database: " + ex.getMessage());
            ex.printStackTrace();
        }



        adminButton.addActionListener(e -> {
            try {
                if (validateLogin("ADMIN")) {
                    new LibraryGUI(true, connection);
                    frame.dispose();
                }
                else
                {
                    JOptionPane.showMessageDialog(frame,"Invalid admin credentials!");
                }
            } catch (SQLException ex) {
                throw new RuntimeException(ex);
            }
        });

        customerButton.addActionListener(e -> {
            try {
                if (validateLogin("CUSTOMEr")){
                new LibraryGUI(false,connection);
                frame.dispose();
                }
                else{
                    JOptionPane.showMessageDialog(frame,"Invalid Customer Credentials!");
                }
            } catch (SQLException ex) {
                throw new RuntimeException(ex);
            }
        });
        JPanel inputPanel = new JPanel(new GridLayout(2, 2));
        inputPanel.add(usernameLabel);
        inputPanel.add(usernameField);
        inputPanel.add(passwordLabel);
        inputPanel.add(passwordField);

        JPanel panel = new JPanel();
        panel.setLayout(new GridLayout(6, 1));

        panel.add(titleLabel);
        panel.add(welcome);
        panel.add(inputPanel);
        panel.add(adminButton);
        panel.add(customerButton);

        frame.add(panel);
        frame.pack();
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);
    }
    private boolean validateLogin(String role) throws  SQLException{
        String username = usernameField.getText();
        String password = new String((passwordField.getPassword()));
        try (PreparedStatement ps = connection.prepareStatement("Select * From users Where username = ? And password = ? AND role =?")){
            ps.setString(1,username);
            ps.setString(2,password);
            ps.setString(3,role);
            try(ResultSet rs = ps.executeQuery()){
                return rs.next();
            }

        }catch (SQLException ex){
            JOptionPane.showMessageDialog(frame,"Error: " + ex.getMessage());
            return false;
        }
    }
    public static void main(String[] args){
        new LoginScreen();
    }
}
