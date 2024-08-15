import java.util.Scanner;

class Employee
{
    int salary, noOfHours;

    void getInfo(int sal, int hours)
    {
        salary = sal;
        noOfHours = hours;
    }

    void AddSalary(int sal)
    {
        if(sal < 500)
        {
            System.out.print("Salary increased by 10 as salary less than 500\n");
            salary = salary + 10;
        }
    }

    void AddHourWork(int hoursWorked)
    {
        if(hoursWorked > 6)
        {
            System.out.print("Salary increased by 5 as hours more than 6\n");

            salary = salary + 5;
        }
    }
}

class Main
{
    public static void main(String[] args)
    {
        int salary, noOfHours;
        Scanner sc = new Scanner(System.in);

        System.out.print("Input salary:\n");
        salary=sc.nextInt();
        System.out.print("Input hours worked:\n");
        noOfHours = sc.nextInt();

        Employee employee1 = new Employee();
        employee1.getInfo(salary,noOfHours);
        employee1.AddSalary(salary);
        employee1.AddHourWork(noOfHours);

        System.out.print("Salary: ");
        System.out.println(employee1.salary);
    }
}