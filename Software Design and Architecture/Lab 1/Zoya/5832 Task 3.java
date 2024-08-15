import java.util.Scanner;
class Pascal
{
    public static void main(String[] args)
    {
        Scanner x = new Scanner(System.in);
        int noOfRows, n;
        
        System.out.print("Input number of rows: ");
        noOfRows = x.nextInt();
        
        for (int i = 0; i < noOfRows; i++) {
            n = 1;
            System.out.format("%" + (noOfRows - i) * 2 + "s", "");
            for (int j = 0; j <= i; j++) 
            {
                System.out.format("%4d", n);
                n = n * (i - j) / (j + 1);
            }
            
            System.out.println();
        }
    }
}
