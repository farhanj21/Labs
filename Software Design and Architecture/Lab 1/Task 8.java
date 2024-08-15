import java.util.Scanner;

class Employee
{
    int salary, hoursWorked;

    void getInfo(int s, int h)
    {
        salary = s;
        hoursWorked = h;
    }

    void AddSal(int s)
    {
        if(s < 500)
        {
            System.out.print("Salary increased by $10 as it is less than 500\n");
            salary = salary + 10;
        }
    }

    void AddWork(int workedHours)
    {
        if(workedHours > 6)
        {
            System.out.print("Salary increased by $5 as hours worked is more than 6\n");

            salary = salary + 5;
        }
    }
}

class Main
{
    public static void main(String[] args)
    {
        int salary, hoursWorked;
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter salary:\n");
        salary=sc.nextInt();
        System.out.print("Enter number of hours works worked:\n");
        hoursWorked = sc.nextInt();

        Employee e = new Employee();
        e.getInfo(salary,hoursWorked);
        e.AddSal(salary);
        e.AddWork(hoursWorked);

        System.out.print("Salary is $");
        System.out.println(e.salary);
    }
}