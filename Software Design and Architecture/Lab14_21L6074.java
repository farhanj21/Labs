import java.util.Scanner;
class DB_CONNECTION
{
    public void connectDB(String dbms)
    {
        if (dbms.equals("mysql")) {
            Mysql obj1 = new Mysql();
            obj1.dbConnection();
        } else if (dbms.equals("postgrel"))
        {
            Postgrel obj2 = new Postgrel();
            obj2.dbConnection();
        } else if (dbms.equals("mongodb"))
        {
            MongoDB obj3 = new MongoDB();
            obj3.dbConnection();
        } else {
            System.out.println("Invalid DBMS specified.");
        }
    }
}

class Main {
    public static void main(String[] args) {
        DB_CONNECTION mainObj = new DB_CONNECTION();

        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the DBMS name: ");
        String dbms = scanner.nextLine();

        mainObj.connectDB(dbms);

        scanner.close();
    }
}

