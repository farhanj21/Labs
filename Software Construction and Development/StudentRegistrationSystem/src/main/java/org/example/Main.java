package org.example;
import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.sql.SQLException;
import java.util.List;

class RegistrationPanel extends JPanel {
    private JTextField nameField;
    private JTextField ageField;
    private JButton registerButton;

    public RegistrationPanel() {
        setLayout(new FlowLayout(FlowLayout.CENTER));

        JPanel namePanel = new JPanel(new BorderLayout());
        nameField = new JTextField(20);
        namePanel.add(new JLabel("Name:"), BorderLayout.WEST);
        namePanel.add(nameField, BorderLayout.CENTER);

        JPanel agePanel = new JPanel(new BorderLayout());
        ageField = new JTextField(20);
        agePanel.add(new JLabel("Age:"), BorderLayout.WEST);
        agePanel.add(ageField, BorderLayout.CENTER);

        registerButton = new JButton("Register");
        registerButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                String name = nameField.getText();
                int age;

                try {
                    age = Integer.parseInt(ageField.getText());
                    if (age < 5 || age > 50) {
                        JOptionPane.showMessageDialog(null, "Age must be between 5 and 50.");
                        return;
                    }
                } catch (NumberFormatException ex) {
                    JOptionPane.showMessageDialog(null, "Enter Valid Age");
                    return;
                }

                Student student = new Student(0, name, age);
                StudentDAO studentDAO = null;
                try {
                    studentDAO = new StudentDAO(DBConnection.getConnection());
                } catch (SQLException ex) {
                    throw new RuntimeException(ex);
                }

                try {
                    studentDAO.addStudent(student);
                    JOptionPane.showMessageDialog(null, "Student Successfully Registered");
                } catch (Exception ex) {
                    JOptionPane.showMessageDialog(null, "Error: " + ex.getMessage());
                }
                nameField.setText("");
                ageField.setText("");
            }
        });

        add(registerButton);
        add(namePanel);
        add(agePanel);
        add(registerButton);
    }
}
class ViewStudentsPanel extends JPanel {
    private JButton viewButton;
    private JTextArea viewStudents;

    public ViewStudentsPanel() {
        setLayout(new BorderLayout());

        viewButton = new JButton("View Registered Students");
        viewButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {

                StudentDAO studentDAO = null;
                try {
                    studentDAO = new StudentDAO(DBConnection.getConnection());
                } catch (SQLException ex) {
                    throw new RuntimeException(ex);
                }


                try {
                    List<Student> students = studentDAO.getAllStudents();

                    StringBuilder studentsDisplay = new StringBuilder();
                    for (Student student : students) {
                        studentsDisplay.append("StudentID: ").append(student.getStudentId()).append(", Name: ").append(student.getStudentName())
                                .append(", Age: ").append(student.getStudentAge())
                                .append("\n");
                    }

                    viewStudents.setText(studentsDisplay.toString());
                } catch (Exception ex) {
                    JOptionPane.showMessageDialog(null, "Error retrieving students: " + ex.getMessage());
                }
            }
        });

        add(viewButton, BorderLayout.NORTH);

        viewStudents = new JTextArea();
        viewStudents.setEditable(false);
        add(new JScrollPane(viewStudents), BorderLayout.CENTER);
    }
}

class MainMenuPanel extends JPanel {
    private JButton addStudentButton;
    private JButton viewStudentsButton;

    public MainMenuPanel(JFrame mainFrame) {
        setLayout(new FlowLayout(FlowLayout.CENTER));

        addStudentButton = new JButton("Add Student");
        addStudentButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                mainFrame.setContentPane(new RegistrationPanel());
                mainFrame.revalidate();
            }
        });
        add(addStudentButton);

        viewStudentsButton = new JButton("View Students");
        viewStudentsButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                mainFrame.setContentPane(new ViewStudentsPanel());
                mainFrame.revalidate();
            }
        });
        add(viewStudentsButton);
    }
}
public class Main {
    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> {
            createAndShowGUI();
        });
    }

    private static void createAndShowGUI() {
        JFrame frame = new JFrame("Student Registration System");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(300, 200);
        frame.setLayout(new BorderLayout());

        MainMenuPanel menuPanel = new MainMenuPanel(frame);
        frame.add(menuPanel, BorderLayout.CENTER);

        frame.setVisible(true);
    }
}
