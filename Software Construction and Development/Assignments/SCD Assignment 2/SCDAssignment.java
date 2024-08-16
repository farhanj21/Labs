import java.util.*;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

class Skill 
{
    private String name;
    private int experience;

    public Skill(String name, int experience) 
    {
        this.name = name;
        this.experience = experience;
    }

    public String getName() 
    {
        return name;
    }

    public int getExperience() 
    {
        return experience;
    }
}

class Resource 
{
    private String name;
    private List<Skill> skills;

    public Resource(String name, List<Skill> skills) 
    {
        this.name = name;
        this.skills = skills;
    }

    public String getName() 
    {
        return name;
    }

    public List<Skill> getSkills() 
    {
        return skills;
    }
}

class Task 
{
    private String name;
    private Map<Skill, Character> requiredSkills;

    public Task(String name, Map<Skill, Character> requiredSkills) 
    {
        this.name = name;
        this.requiredSkills = requiredSkills;
    }

    public String getName() 
    {
        return name;
    }

    public Map<Skill, Character> getRequiredSkills() 
    {
        return requiredSkills;
    }
}

interface MatchingStrategy 
{
    boolean isMatch(Resource resource, Task task);
}

class ExactMatch implements MatchingStrategy
{
    @Override
    public boolean isMatch(Resource resource, Task task) 
    {
        Map<Skill, Character> requiredSkills = task.getRequiredSkills();

        for (Map.Entry<Skill, Character> entry : requiredSkills.entrySet()) {
            Skill requiredSkill = entry.getKey();
            Character requiredLevel = entry.getValue();

            for (Skill resourceSkill : resource.getSkills()) {
                if (resourceSkill.getName().equals(requiredSkill.getName()) &&
                    resourceSkill.getExperience() >= getRequiredExperience(requiredLevel)) {
                    return true;
                }
            }
        }
        return false;
    }

    private int getRequiredExperience(char level) 
    {
        switch (level) {
            case 'b':
                return 1;
            case 'i':
                return 2;
            case 'e':
                return 3;
            default:
                return 0;
        }
    }
}

class SkillOnlyMatch implements MatchingStrategy 
{
    @Override
    public boolean isMatch(Resource resource, Task task) {
        Map<Skill, Character> requiredSkills = task.getRequiredSkills();

        for (Map.Entry<Skill, Character> entry : requiredSkills.entrySet()) {
            Skill requiredSkill = entry.getKey();
            for (Skill resourceSkill : resource.getSkills()) {
                if (resourceSkill.getName().equals(requiredSkill.getName())) {
                    return true;
                }
            }
        }
        return false;
    }
}


public class SCDAssignment 
{
    public static void main(String[] args) 
    {
        List<Resource> resources = loadResourcesFromFile("applicants.txt");
        List<Task> tasks = loadTasksFromFile("tasks.txt");

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


