class stringEnd
{
    public static void main(String[] args)
    {
        String s1 = "Python Exercises";
        String s2 = "se";
        System.out.println(s1 + " ends with " + s2 + "?\n" + s1.endsWith(s2));

        s1 = "Python Exercise";
        System.out.println(s1 + " ends with " + s2 + "?\n" + s1.endsWith(s2));
    }
}
