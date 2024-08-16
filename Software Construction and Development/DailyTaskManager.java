import java.sql.*;
import javax.swing.*;
import java.awt.event.*;


public class TaskManager {
    private Connection connect() {
        // Your database credentials
        String url = "jdbc:mysql://localhost:3306/task_manager";
        String user = "root";
        String password = "1337";

        Connection conn = null;
        try {
            conn = DriverManager.getConnection(url, user, password);
        } catch (SQLException e) {
            System.out.println(e.getMessage());
        }
        return conn;
    }

    public void addTask(String taskDescription) {
        String sql = "INSERT INTO tasks(task_description, is_completed) VALUES(?, false)";
        
        try (Connection conn = this.connect();
             PreparedStatement pstmt = conn.prepareStatement(sql)) {
            pstmt.setString(1, taskDescription);
            pstmt.executeUpdate();
        } catch (SQLException e) {
            System.out.println(e.getMessage());
        }
    }

    public void viewTasks() {
        String sql = "SELECT * FROM tasks";

        try (Connection conn = this.connect();
             Statement stmt  = conn.createStatement();
             ResultSet rs    = stmt.executeQuery(sql)) {
            
            while (rs.next()) {
                System.out.println(rs.getInt("task_id") +  "\t" +
                                   rs.getString("task_description") + "\t" +
                                   rs.getBoolean("is_completed"));
            }
        } catch (SQLException e) {
            System.out.println(e.getMessage());
        }
    }

    public void removeTask(int taskId) {
        String sql = "DELETE FROM tasks WHERE task_id = ?";

        try (Connection conn = this.connect();
             PreparedStatement pstmt = conn.prepareStatement(sql)) {

            pstmt.setInt(1, taskId);
            pstmt.executeUpdate();

        } catch (SQLException e) {
            System.out.println(e.getMessage());
        }
    }
};


public class TaskManagerGUI {

    private TaskManager taskManager;

    public TaskManagerGUI() {
        taskManager = new TaskManager();
        JFrame frame = new JFrame();

        JTextField taskInput = new JTextField(20);
        JButton addButton = new JButton("Add Task");
        JButton viewButton = new JButton("View Tasks");
        JButton removeButton = new JButton("Remove Task");
        JTextField taskIdInput = new JTextField(5);
        
        addButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                taskManager.addTask(taskInput.getText());
            }
        });

        viewButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                taskManager.viewTasks();
            }
        });

        removeButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                int taskId = Integer.parseInt(taskIdInput.getText());
                taskManager.removeTask(taskId);
            }
        });

        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.pack();
        frame.setVisible(true);
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(new Runnable() {
            public void run() {
                new TaskManagerGUI();
            }
        });
    }
}