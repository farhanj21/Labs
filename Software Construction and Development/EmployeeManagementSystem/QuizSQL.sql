CREATE DATABASE EmployeeManagement;
use EmployeeManagement;

CREATE TABLE Employee (
     employee_ID INT PRIMARY KEY AUTO_INCREMENT,
    employee_name VARCHAR(255),
    employee_position VARCHAR(255),
    employee_salary double
);


INSERT INTO Employee (employee_ID, employee_name, employee_position,  employee_salary) VALUES (1, 'Farhan Jafri', 'Manager', 100.0);
INSERT INTO Employee (employee_ID, employee_name, employee_position,  employee_salary) VALUES (2, 'Lionel Messi', 'Human Resource', 100.0);
INSERT INTO Employee (employee_ID, employee_name, employee_position,  employee_salary) VALUES (3, 'Sebastian Vettel', 'Employee', 100.0);
INSERT INTO Employee (employee_ID, employee_name, employee_position,  employee_salary) VALUES (4, 'Max Verstappen', 'Employee', 100.0);
INSERT INTO Employee (employee_ID, employee_name, employee_position,  employee_salary) VALUES (5, 'Babar Azam', 'Employee', 100.0);
