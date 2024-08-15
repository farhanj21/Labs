class PentagonalNumbers
{
    public static void main(String[] args)
        {
            print(50);
        }
    public static void print(int n)
    {
        int PentagonalNumber;
        for (int i = 1; i <= n; i++) {
            PentagonalNumber = i * (3 * i - 1) / 2;
            System.out.print(PentagonalNumber + " ");
        }
        System.out.println();
    }
}