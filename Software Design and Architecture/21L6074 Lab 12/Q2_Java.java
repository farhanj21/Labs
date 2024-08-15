import java.util.ArrayList;
import java.util.List;

interface Observer {
    void update(int runs, int wickets, float overs);
}

class CricketData {
    private int runs;
    private int wickets;
    private float overs;
    private List<Observer> observers;

    public CricketData() {
        observers = new ArrayList<>();
    }

    public void registerObserver(Observer observer) {
        observers.add(observer);
    }

    public void unregisterObserver(Observer observer) {
        observers.remove(observer);
    }

    public void notifyObservers() {
        for (Observer observer : observers) {
            observer.update(runs, wickets, overs);
        }
    }

    private int getRuns() {
        return runs;
    }

    private int getWickets() {
        return wickets;
    }

    private float getOvers() {
        return overs;
    }

    public void dataChanged() {
        runs = getLatestRuns();
        wickets = getLatestWickets();
        overs = getLatestOvers();

        notifyObservers();
    }

    private int getLatestRuns() {
        return 90;
    }

    private int getLatestWickets() {
        return 2;
    }

    // get latest overs from stadium
    private float getLatestOvers() {
        // return 9.3 for simplicity
        return (float) 9.3;
    }
}

class CurrentScoreDisplay implements Observer {
    private int runs;
    private int wickets;
    private float overs;
    private CricketData cricketData;

    public CurrentScoreDisplay(CricketData cricketData) {
        this.cricketData = cricketData;
        cricketData.registerObserver(this);
    }

    public void update(int runs, int wickets, float overs) {
        this.runs = runs;
        this.wickets = wickets;
        this.overs = overs;
        display();
    }

    public void display() {
        System.out.println("\nCurrent Score Display: \n" +
                "Runs: " + runs + "\n" +
                "Wickets: " + wickets + "\n" +
                "Overs: " + overs);
    }
}

class AverageScoreDisplay implements Observer {
    private float runRate;
    private int predictedScore;
    private CricketData cricketData;

    public AverageScoreDisplay(CricketData cricketData) {
        this.cricketData = cricketData;
        cricketData.registerObserver(this);
    }

    public void update(int runs, int wickets, float overs) {
        this.runRate = (float) runs / overs;
        this.predictedScore = (int) (this.runRate * 50);
        display();
    }

    public void display() {
        System.out.println("\nAverage Score Display: \n" +
                "Run Rate: " + runRate + "\n" +
                "Predicted Score: " + predictedScore);
    }
}

public class Main {
    public static void main(String[] args) {
        CricketData cricketData = new CricketData();

        CurrentScoreDisplay currentScoreDisplay = new CurrentScoreDisplay(cricketData);
        AverageScoreDisplay averageScoreDisplay = new AverageScoreDisplay(cricketData);

        cricketData.dataChanged();
    }
}
