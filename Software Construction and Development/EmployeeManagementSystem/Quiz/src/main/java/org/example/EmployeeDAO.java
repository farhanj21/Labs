package org.example;

import java.sql.*;
import java.util.ArrayList;
import java.util.List;

public class EmployeeDAO {
    private final Connection connection;

    public EmployeeDAO(Connection connection) {
        this.connection = connection;
    }

    public void addEmployee(Employee emp) throws SQLException {
        String sql = "INSERT INTO Employee (employee_name, employee_position,  employee_salary) VALUES (?, ?, ?)";
        try (PreparedStatement pstmt = connection.prepareStatement(sql)) {
            pstmt.setString(1, emp.getemployee_name());
            pstmt.setString(2, emp.getEmployee_position());
            pstmt.setDouble(3, emp.getemployee_salary());
            pstmt.executeUpdate();
        }
    }

    public List<Employee> getAllEmployees() throws SQLException {
        List<Employee> Employee = new ArrayList<>();
        String sql = "SELECT * FROM Employee";
        try (PreparedStatement pstmt = connection.prepareStatement(sql);
             ResultSet rs = pstmt.executeQuery()) {
            while (rs.next()) {
                Employee emp = new Employee(
                        rs.getInt("employee_id"),
                        rs.getString("employee_name"),
                        rs.getString("employee_position"),
                        rs.getDouble("employee_salary"));
                Employee.add(emp);
            }
        }
        return Employee;
    }

    public void updateEmployee(Employee emp) throws SQLException {
        String sql = "UPDATE Employee SET employee_name=?, employee_position=?, employee_salary=? WHERE employee_id=?";
        try (PreparedStatement pstmt = connection.prepareStatement(sql)) {
            pstmt.setString(1, emp.getemployee_name());
            pstmt.setString(2, emp.getEmployee_position());
            pstmt.setDouble(3, emp.getemployee_salary());
            pstmt.setInt(4, emp.getemployee_ID());
            pstmt.executeUpdate();
        }
    }

    public void deleteEmployee(int employeeID) throws SQLException {
        String sql = "DELETE FROM Employee WHERE employee_id=?";
        try (PreparedStatement pstmt = connection.prepareStatement(sql)) {
            pstmt.setInt(1, employeeID);
            pstmt.executeUpdate();
        }
    }

}
