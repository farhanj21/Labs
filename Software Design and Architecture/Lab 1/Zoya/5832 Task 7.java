class Employee
{
    private String name, address;
    private int year, salary;
    public Employee(String inName, int inYear, int inSalary, String inAddress)
    {
        name = inName;
        year = inYear;
        salary = inSalary;
        address = inAddress;
    }
    public String getName()
    {
        return name;
    }
    public int getYear()
    {
        return year;
    }
    public int getSalary()
    {
        return salary;
    }
    public String getAddress()
    {
        return address;
    }
    public void Print()
    {
        System.out.println(getName()+"\t"+getYear()+"\t"+getSalary()+"\t"+getAddress());

    }
}

class EmployeeTask7
{
    public static void main(String[] args)
    {
        Employee employee1 = new Employee("Robert", 1994, 500000, "64C- WallsStreet");
        Employee employee2 = new Employee("Sam", 2000, 740000, "68d- WallsStreet");
        Employee employee3 = new Employee("John", 1999, 600000, "26B- WallsStreet");

        System.out.println("Name\tYear\tSalary\tAddress");
        employee1.Print();
        employee2.Print();
        employee3.Print();


    }
}