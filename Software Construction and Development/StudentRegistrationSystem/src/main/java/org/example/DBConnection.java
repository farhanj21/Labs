package org.example;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

public class DBConnection
{
    private static final String DATABASE_URL = "jdbc:mysql://localhost:3306/StudentsDB";
    private static final String DATABASE_USER = "root";
    private static final String DATABASE_PASSWORD = "1337";


    public static Connection getConnection() throws SQLException {
        return DriverManager.getConnection(DATABASE_URL, DATABASE_USER, DATABASE_PASSWORD);
    }
}