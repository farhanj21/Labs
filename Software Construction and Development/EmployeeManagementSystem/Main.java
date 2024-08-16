package org.example;
import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.sql.SQLException;
import java.util.List;

class RegistrationPanel extends JPanel {
    private JTextField nameField;
    private JTextField positionField;
    private JTextField salaryField;
    private JButton registerButton;

    public RegistrationPanel() {
        setLayout(new FlowLayout(FlowLayout.CENTER));

        JPanel namePanel = new JPanel(new BorderLayout());
        nameField = new JTextField(20);
        namePanel.add(new JLabel("Name:"), BorderLayout.WEST);
        namePanel.add(nameField, BorderLayout.CENTER);

        JPanel positionPanel = new JPanel(new BorderLayout());
        positionField = new JTextField(20);
        positionPanel.add(new JLabel("Position:"), BorderLayout.WEST);
        positionPanel.add(positionField, BorderLayout.CENTER);

        JPanel salaryPanel = new JPanel(new BorderLayout());
        salaryField = new JTextField(20);
        salaryPanel.add(new JLabel("Salary:"), BorderLayout.WEST);
        salaryPanel.add(salaryField, BorderLayout.CENTER);

        registerButton = new JButton("Register");
        registerButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                String name = nameField.getText();
                String position = positionField.getText();
                Double salary = Double.parseDouble(salaryField.getText());
                
                Employee employee = new Employee(0, name, position, salary);
                EmployeeDAO EmployeeDAO = null;
                try {
                    EmployeeDAO = new EmployeeDAO(DBConnection.getConnection());
                } catch (SQLException ex) {
                    throw new RuntimeException(ex);
                }

                try {
                    EmployeeDAO.addEmployee(employee);
                    JOptionPane.showMessageDialog(null, "Employee Successfully Registered");
                } catch (Exception ex) {
                    JOptionPane.showMessageDialog(null, "Error: " + ex.getMessage());
                }
                nameField.setText("");
                positionField.setText("");
            }
        });

        add(registerButton);
        add(namePanel);
        add(positionPanel);
        add(salaryPanel);
        add(registerButton);
    }
}
class ViewEmployeesPanel extends JPanel {
    private JButton viewButton;
    private JTextArea viewEmployees;

    public ViewEmployeesPanel() {
        setLayout(new BorderLayout());

        viewButton = new JButton("View Registered Employees");
        viewButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {

                EmployeeDAO EmployeeDAO = null;
                try {
                    EmployeeDAO = new EmployeeDAO(DBConnection.getConnection());
                } catch (SQLException ex) {
                    throw new RuntimeException(ex);
                }


                try {
                    List<Employee> employeess = EmployeeDAO.getAllEmployees();

                    StringBuilder employeePrint = new StringBuilder();
                    for (Employee employee : employeess) {
                        employeePrint.append("EmployeeID: ").append(employee.getemployee_ID()).append(", Name: ").append(employee.getemployee_name())
                                .append(", Position: ").append(employee.getEmployee_position()).append(" Salary: ").append(employee.getemployee_salary())
                                .append("\n");
                    }

                    viewEmployees.setText(employeePrint.toString());
                } catch (Exception ex) {
                    JOptionPane.showMessageDialog(null, "Error retrieving employeess: " + ex.getMessage());
                }
            }
        });

        add(viewButton, BorderLayout.NORTH);

        viewEmployees = new JTextArea();
        viewEmployees.setEditable(false);
        add(new JScrollPane(viewEmployees), BorderLayout.CENTER);
    }
}

class MainMenuPanel extends JPanel {
    private JButton addEmployeeButton;
    private JButton viewEmployeesButton;

    public MainMenuPanel(JFrame mainFrame) {
        setLayout(new FlowLayout(FlowLayout.CENTER));

        addEmployeeButton = new JButton("Add Employee");
        addEmployeeButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                mainFrame.setContentPane(new RegistrationPanel());
                mainFrame.revalidate();
            }
        });
        add(addEmployeeButton);

        viewEmployeesButton = new JButton("View Employees");
        viewEmployeesButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                mainFrame.setContentPane(new ViewEmployeesPanel());
                mainFrame.revalidate();
            }
        });
        add(viewEmployeesButton);
    }
}
public class Main {
    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> {
            createAndShowGUI();
        });
    }

    private static void createAndShowGUI() {
        JFrame frame = new JFrame("Employee Registration System");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(300, 200);
        frame.setLayout(new BorderLayout());

        MainMenuPanel menuPanel = new MainMenuPanel(frame);
        frame.add(menuPanel, BorderLayout.CENTER);

        frame.setVisible(true);
    }
}
