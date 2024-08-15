class Employee{
    private String name, address;
    private int year, salary;
    public Employee(String inputname, int inputyear, int inputsalary, String inputaddress)
    {
      name = inputname;
      year = inputyear;
      salary = inputsalary;
      address = inputaddress;
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
    public void Display()
    {
        System.out.println(name+"\t    "+year+"\t "+salary+"\t   "+address+"\n");  
   
    }
  }
  
  class Emp
  {
    public static void main(String[] args)
    {
      Employee e1 = new Employee("Robert", 1994, 500000, "64C- WallsStreet");
      Employee e2 = new Employee("Sam", 2000, 740000, "68d- WallsStreet");
      Employee e3 = new Employee("John", 1999, 600000, "26B- WallsStreet");
    
      System.out.println("Name\tYear of joining\t Salary\t      Address "+"\n");
      e1.Display();
      e2.Display();
      e3.Display();
    }
  }