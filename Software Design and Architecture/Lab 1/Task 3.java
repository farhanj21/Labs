import java.util.Scanner;
class pascaltriangle
{
    public static void main(String[] args)
    {
        Scanner x = new Scanner(System.in);
        System.out.print("Input number of rows: ");
        int rows = x.nextInt();
        for (int i = 0; i < rows; i++) {
            int number = 1;
            System.out.format("%" + (rows - i) * 2 + "s", "");
            for (int j = 0; j <= i; j++) {
                System.out.format("%4d", number);
                number = number * (i - j) / (j + 1);
            }
            System.out.println();
        }
    }
}
