class pentNums
{
    public static void main(String[] args)
    {
        print(50);
    }

    public static void print(int n)
    {
        for (int i = 1; i <= n; i++) {
            int pentNum = i * (3 * i - 1) / 2;
            System.out.print(pentNum + " ");
        }
        System.out.println();
    }
}