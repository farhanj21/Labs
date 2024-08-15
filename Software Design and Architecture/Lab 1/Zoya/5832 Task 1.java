import java.util.Scanner;
class speed
{
    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in);

       double distance, timeinSeconds, metersPerSeconds, kilometerPerHour, milesPerHour;
       int hours, minutes, seconds;

        System.out.print("Please enter distance in meters: ");
        distance = input.nextDouble();

        System.out.print("Enter hours, minutes and seconds: ");
        hours = input.nextInt();
        minutes = input.nextInt();
        seconds = input.nextInt();
        input.close();

        timeinSeconds = (hours * 3600) + (minutes * 60) + seconds;
        metersPerSeconds = distance / timeinSeconds;
        kilometerPerHour = (distance / 1000.0) / (timeinSeconds / 3600.0);
        milesPerHour = kilometerPerHour / 1.609;

        System.out.println("Speed in m/s is " + metersPerSeconds);
        System.out.println("Speed in km/h is " + kilometerPerHour);
        System.out.println("Speed in miles/h is " + milesPerHour);
    }
}
