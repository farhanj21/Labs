public class Calculator 
{
    public static double addition(double num1, double num2) {
        return num1 + num2;
    }
    
    public static double subtraction(double num1, double num2) {
        return num1 - num2;
    }
    public static double multiplication(double num1, double num2) {
        return num1 * num2;
    }

    public static double division(double num1, double num2) {
        return num1 / num2;
    }

    public static void main(String[] args) {
        double num1 = 14.0;
        double num2 = 5.0;
        
        System.out.println("Using " + num1 + " and "+ num2);

        System.out.println("Addition: " + addition(num1, num2));
        System.out.println("Subtraction: " + subtraction(num1, num2));
        System.out.println("Multiplication: " + multiplication(num1, num2));
        System.out.println("Division: " + division(num1, num2));
    }
}
