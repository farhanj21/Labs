abstract class WorkoutTracker 
{
   
    public final void trackWorkout() 
    {
        
        String workoutType = getWorkoutType();
        System.out.println("Tracking " + workoutType + " workout...");
        String workoutData = getWorkoutData();
        System.out.println("Workout data: " + workoutData);
        analyzeWorkoutData(workoutData);
        saveWorkoutData(workoutType, workoutData);

        System.out.println(workoutType + " workout tracked and saved successfully!");
    }

    protected abstract String getWorkoutType();
    protected abstract String getWorkoutData();
    protected abstract void analyzeWorkoutData(String workoutData);
    protected abstract void saveWorkoutData(String workoutType, String workoutData);
}

class RunningTracker extends WorkoutTracker 
{
    @Override
    protected String getWorkoutType() 
    {
        return "Running";
    }

    @Override
    protected String getWorkoutData() 
    {
     
        double distance = 5.0; 
        double pace = 8.0; 
        return "Distance: " + distance + "km, Pace: " + pace + "min/km";
    }

    @Override
    protected void analyzeWorkoutData(String workoutData) 
    {
        double distance = Double.parseDouble(workoutData.split(",")[0].split(":")[1].trim());
        double time = Double.parseDouble(workoutData.split(",")[1].split(":")[1].trim());
        double averageSpeed = distance / (time / 60);
        System.out.println("Average speed: " + averageSpeed + "km/h");
    }

    @Override
    protected void saveWorkoutData(String workoutType, String workoutData)
    {
        System.out.println("Saving " + workoutType + " workout data: " + workoutData);
    }
}

class WeightliftingTracker extends WorkoutTracker 
{
    @Override
    protected String getWorkoutType() {
        return "Weightlifting";
    }

    @Override
    protected String getWorkoutData() {
        
        int reps = 10; 
        int sets = 3; 
        return "Reps: " + reps + ", Sets: " + sets;
    }

    @Override
    protected void analyzeWorkoutData(String workoutData) {
        int reps = Integer.parseInt(workoutData.split(",")[0].split(":")[1].trim());
        int sets = Integer.parseInt(workoutData.split(",")[1].split(":")[1].trim());
        int totalReps = reps * sets;
        System.out.println("Total reps: " + totalReps);
}

@Override
protected void saveWorkoutData(String workoutType, String workoutData) {
    System.out.println("Saving " + workoutType + " workout data: " + workoutData);
}
}

class WorkoutTrackerApp 
{
public static void main(String[] args) 
{
WorkoutTracker runningTracker = new RunningTracker();
runningTracker.trackWorkout();
    WorkoutTracker weightliftingTracker = new WeightliftingTracker();
    weightliftingTracker.trackWorkout();
}

}