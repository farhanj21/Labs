class ControlSystem {

    private String elevatorId;

    public boolean externalButtonLight() {
        throw new UnsupportedOperationException("Not supported yet.");
    }

    public boolean internalButtonLight() {
        throw new UnsupportedOperationException("Not supported yet.");
    }

    public boolean doorOpenClose() {
        throw new UnsupportedOperationException("Not supported yet.");
    }

    public int moveElevator(int destination) {
        throw new UnsupportedOperationException("Not supported yet.");
    }
}

class Elevator {

    private int currFloor;

    private int destFloor;

    public void move(int floor) {
    }
}

class Passenger 
{

    private int currFloor;

    private int destFloor;

    public void elevatorCall() {
    }

    public int chooseDestination(int destination) {
        throw new UnsupportedOperationException("Not supported yet.");
    }
}

