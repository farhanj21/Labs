
interface Vehicle
{
   public void accelerate();
    public void brake();
    public void steer();
}

class Car implements Vehicle
{
    public void accelerate() {
        System.out.println("Car is accelerating");
    }
    public void brake() {
        System.out.println("Car is braking");
    }
    public void steer() {
        System.out.println("Car is steering");
    }
}

class Bus implements Vehicle
{
    public void accelerate() {
        System.out.println("Bus is accelerating");
    }
    public void brake() {
        System.out.println("Bus is braking");
    }
    public void steer() {
        System.out.println("Bus is steering");
    }
}

class Truck implements Vehicle {
    public void accelerate() {
        System.out.println("Truck is accelerating");
    }
    public void brake() {
        System.out.println("Truck is braking");
    }
    public void steer() {
        System.out.println("Truck is steering");
    }
}

class VehicleFactory
{
    public static Vehicle createVehicle(String type) {
        if (type.equals("car")) {
            return new Car();
        } else if (type.equals("bus")) {
            return new Bus();
        } else if (type.equals("truck")) {
            return new Truck();
        } else {
            throw new IllegalArgumentException("Invalid vehicle type");
        }
    }
}
