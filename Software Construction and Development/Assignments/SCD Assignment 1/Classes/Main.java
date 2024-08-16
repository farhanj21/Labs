import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class Main
{
    public static void main(String[] args)
    {
        List<Resource> resources = loadResourcesFromFile("C:\\Users\\Omer Habib\\Downloads\\Python Labs\\skill.txt");
        List<Task> tasks = loadTasksFromFile("C:\\Users\\Omer Habib\\Downloads\\Python Labs\\task.txt");

        MatchingStrategy matchingStrategy = new ExactMatch();

        matchTasksToResources(resources, tasks, matchingStrategy);
    }

    private static List<Resource> loadResourcesFromFile(String fileName)
    {
        List<Resource> resources = new ArrayList<>();
        try (BufferedReader br = new BufferedReader(new FileReader(fileName))) {
            String line;
            while ((line = br.readLine()) != null) {
                String[] parts = line.split("\\|");
                String name = parts[0].trim();
                String[] skillStrings = parts[1].split(",");
                List<Skill> skills = new ArrayList<>();

                for (String skillString : skillStrings) {
                    String[] skillParts = skillString.trim().split(":");
                    String skillName = skillParts[0].trim();
                    int experience = Integer.parseInt(skillParts[1].trim());
                    Skill skill = new Skill(skillName, experience);
                    skills.add(skill);
                }

                Resource resource = new Resource(name, skills);
                resources.add(resource);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
        return resources;
    }

    private static List<Task> loadTasksFromFile(String fileName) {
        List<Task> tasks = new ArrayList<>();
        try (BufferedReader br = new BufferedReader(new FileReader(fileName))) {
            String line;
            while ((line = br.readLine()) != null) {
                String[] parts = line.split("\\|");
                String taskName = parts[0].trim();
                String[] skillStrings = parts[1].split(",");
                Map<Skill, Character> requiredSkills = new HashMap<>();

                for (String skillString : skillStrings) {
                    String[] skillParts = skillString.trim().split(":");
                    String skillName = skillParts[0].trim();
                    char skillLevel = skillParts[1].trim().charAt(0);
                    requiredSkills.put(new Skill(skillName, 0), skillLevel);
                }

                Task task = new Task(taskName, requiredSkills);
                tasks.add(task);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
        return tasks;
    }

    private static void matchTasksToResources(List<Resource> resources, List<Task> tasks, MatchingStrategy strategy) {
        for (Task task : tasks) {
            System.out.println("Matching for Task: " + task.getName());
            for (Resource resource : resources) {
                if (strategy.isMatch(resource, task)) {
                    System.out.println("  Assigned " + resource.getName());
                }
            }
            System.out.println();
        }
    }
}
