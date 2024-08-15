// import java.util.*; 

// class employee
//  {
//    int salary;
//    int no_of_works;

//    void getinfo(int s, int n)
//    {
//       salary = s;
//       no_of_works = n;
//    }
   
//    void AddSal(int s)
//    {
//        if(s < 500)
//        {
//         System.out.print("Salary Incremented as salary <500 \n ");
//         salary = salary + 10;
//        }
//    }
//    void AddWork(int no_of_work)
//    {
//        if(no_of_work >6)
//        {
//         System.out.print("Salary Incremented as workhours >6  \n ");

//          salary = salary + 5;
//        }
//    }
//  }
//  class Main
// {
//   public static void main(String[] args) 
//   {
//     int salary, no_of_works;
//     Scanner sc = new Scanner(System.in);


//     System.out.print("Enter salary: \n ");
//     salary=sc.nextInt();
//     System.out.print("Enter No of works worked: \n ");
//     no_of_works = sc.nextInt();
   
   
//     employee myemloyee = new employee();
//     myemloyee.getinfo(salary,no_of_works);
//     myemloyee.AddSal(salary);
//     myemloyee.AddWork(no_of_works);
    
//     System.out.print("Salary:  ");
//     System.out.println(myemloyee.salary);
//   }
// }