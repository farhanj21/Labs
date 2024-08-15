import java.util.Scanner;

class SubArrayZero
{
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        int n, total = 0;

        System.out.print("Input number of elements in the array: ");
        n = input.nextInt();

        int[] array = new int[n];
        System.out.println("Input elements in the array: ");
        for (int i = 0; i < n; i++) {
            array[i] = input.nextInt();
        }

        for (int i = 0; i < n; i++)
        {
            total = 0;
            for (int j = i; j < n; j++)
            {
                total = total + array[j];
                if (total == 0) {
                    System.out.print("Subarray found is : ");
                    for (int k = i; k <= j; k++) {
                        System.out.print(array[k] + " ");
                    }
                    System.out.println();
                }
            }
        }
    }
}