package org.example;

public class Employee {
    private int employee_ID;
    private String employee_name;
    
    private String employee_position;
    private double employee_salary;

    public Employee(int employee_ID, String employee_name, String employee_position, double employee_salary) {
        this.employee_ID = employee_ID;
        this.employee_name = employee_name;
        this.employee_position = employee_position;
        this.employee_salary = employee_salary;
    }

    public int getemployee_ID() {
        return employee_ID;
    }

    public void setemployee_ID(int employee_ID) {
        this.employee_ID = employee_ID;
    }

    public String getEmployee_position() {
        return employee_position;
    }
    public String getemployee_name() {
        return employee_name;
    }

    public double getemployee_salary() {
        return employee_salary;
    }

    @Override
    public String toString() {
        return "Employee{" + "employee_ID=" + employee_ID +
                ", employee_name='" + employee_name + '\'' + ", " + "employee_position=" + employee_position +
                "employee_salary=" + employee_salary + '}';
    }
}
