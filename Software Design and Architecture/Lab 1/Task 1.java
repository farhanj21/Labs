import java.util.Scanner;
class speedcalculation
{
    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in);

        System.out.print("Input distance in meters: ");
        double distance = input.nextDouble();

        System.out.print("Input hour: ");
        int hours = input.nextInt();
        System.out.print("Input minutes: ");
        int minutes = input.nextInt();
        System.out.print("Input seconds: ");
        int seconds = input.nextInt();
        input.close();

        double timeinSec = (hours * 3600) + (minutes * 60) + seconds;
        double metersPerSec = distance / timeinSec;
        double kmperHour = (distance / 1000.0) / (timeinSec / 3600.0);
        double milesperhour = kmperHour / 1.609;

        System.out.println("Your speed in meters/second: " + metersPerSec);
        System.out.println("Your speed in km/h: " + kmperHour);
        System.out.println("Your speed in miles/h: " + milesperhour);
    }
}
