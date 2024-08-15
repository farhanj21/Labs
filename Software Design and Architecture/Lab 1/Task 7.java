class Employee
{
    private String name, address;
    private int year, salary;
    public Employee(String n, int y, int sal, String add)
    {
        name = n;
        year = y;
        salary = sal;
        address = add;
    }
    public String getName()
    {
        return name;
    }
    public int getYear()
    {
        return year;
    }
    public int getSal()
    {
        return salary;
    }
    public String getAdd()
    {
        return address;
    }
}

class Emp
{
    public static void main(String[] args)
    {
        Employee e1 = new Employee("Robert", 1994, 690000, "64C- WallsStreet");
        Employee e2 = new Employee("Sam", 2000, 100000, "68d- WallsStreet");
        Employee e3 = new Employee("John", 1999, 540000, "26B- WallsStreet");

        System.out.println("Name\tYear\tSalary\tAddress");
        System.out.println(e1.getName()+"\t"+e1.getYear()+"\t"+e1.getSal()+"\t"+e1.getAdd());
        System.out.println(e2.getName()+"\t\t"+e2.getYear()+"\t"+e2.getSal()+"\t"+e2.getAdd());
        System.out.println(e3.getName()+"\t"+e3.getYear()+"\t"+e3.getSal()+"\t"+e3.getAdd());
    }
}