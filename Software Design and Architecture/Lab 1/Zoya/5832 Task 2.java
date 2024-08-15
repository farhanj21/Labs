import java.util.Scanner;

class multiplicationTable
{
    public static void main(String[] args)
    {
        int n, num;

        Scanner x = new Scanner(System.in);
        System.out.print("Enter an integer: ");
        n = x.nextInt();
        System.out.print("Input number of terms for table: ");
        num = x.nextInt();

        for (int i = 0; i <= num; i++)
        {
            System.out.println(n + " x " + i + " = " + n * i);
        }
    }
}