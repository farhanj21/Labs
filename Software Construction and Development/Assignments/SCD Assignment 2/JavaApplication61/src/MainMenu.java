import java.awt.FlowLayout;
import javax.swing.*;
import java.io.*;
import java.util.*;
import java.util.stream.Collectors;

class Resource 
{
    private String name;
    private List<Skill> skills = new ArrayList<>();

    public Resource(String name) {
        this.name = name;
    }

    public String getName() {
        return name;
    }

    public List<Skill> getSkills() {
        return skills;
    }

    public void addSkill(Skill skill) {
        skills.add(skill);
    }
}

class Task 
{
    private String name;
    private Map<Skill, Character> requiredSkills = new HashMap<>();

    public Task(String name) {
        this.name = name;
    }

    public String getName() {
        return name;
    }

    public Map<Skill, Character> getRequiredSkills() {
        return requiredSkills;
    }

    public void addRequiredSkill(Skill skill, Character level) { 
        requiredSkills.put(skill, level);
    }
}

class Skill {
    private String name;
    private int experience;

    public Skill(String name, int experience) {
        this.name = name;
        this.experience = experience;
    }
    
    public Skill(String name)
    {
        this.name = name;
    }

    public String getName() {
        return name;
    }

    public int getExperience() {
        return experience;
    }
}


class AllocationGUI 
{
    JFrame frame;
    JList<Resource> resourceList;
    JList<Task> taskList;

    public AllocationGUI() {
        frame = new JFrame("Resource / Task Allocation System");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(400, 300);
    }

   public void displayResourceForm() {
    frame.getContentPane().removeAll();
    frame.repaint();

    JLabel nameLabel = new JLabel("Resource Name:");
    JTextField nameField = new JTextField(15);
    JLabel skillLabel = new JLabel("Skill:");
    JTextField skillField = new JTextField(15);
    JLabel expLabel = new JLabel("Experience:");
    JTextField expField = new JTextField(5);

    JButton addButton = new JButton("Add");
    addButton.addActionListener(e -> {
    String name = nameField.getText();
    String skill = skillField.getText();
    int experience = Integer.parseInt(expField.getText());

    Resource resource = new Resource(name);
    resource.addSkill(new Skill(skill, experience));

    List<Resource> currentResources = loadResourcesFromFile();
    currentResources.add(resource);
    saveResourcesToFile(currentResources);
});

    frame.setLayout(new FlowLayout());
    frame.add(nameLabel);
    frame.add(nameField);
    frame.add(skillLabel);
    frame.add(skillField);
    frame.add(expLabel);
    frame.add(expField);
    frame.add(addButton);
     JButton showContentsButton = new JButton("Show Current Resources");
    showContentsButton.addActionListener(e -> {
        JTextArea textArea = new JTextArea(10, 30);
        JScrollPane scrollPane = new JScrollPane(textArea);
        textArea.setEditable(false);

        try (BufferedReader br = new BufferedReader(new FileReader("applicants.txt"))) {
            String line;
            while ((line = br.readLine()) != null) {
                textArea.append(line + "\n");
            }
        } catch (IOException ex) {
            ex.printStackTrace();
        }

        JOptionPane.showMessageDialog(frame, scrollPane);
    });

    frame.add(showContentsButton);
    frame.setVisible(true);

}

public void displayTaskForm() {
    frame.getContentPane().removeAll();
    frame.repaint();

    JLabel taskLabel = new JLabel("Task Name:");
    JTextField taskField = new JTextField(15);
    JLabel skillLabel = new JLabel("Skill:");
    JTextField skillField = new JTextField(15);
    JLabel levelLabel = new JLabel("Level:");
    JTextField levelField = new JTextField(1);

    JButton addButton = new JButton("Add");
    addButton.addActionListener(e -> {
        String taskName = taskField.getText();
        String skill = skillField.getText();
        Character level = levelField.getText().charAt(0);

        Task task = new Task(taskName);
        task.addRequiredSkill(new Skill(skill, 0), level);

        List<Task> currentTasks = loadTasksFromFile();
        currentTasks.add(task);
        saveTasksToFile(currentTasks);
    });



    frame.setLayout(new FlowLayout());
    frame.add(taskLabel);
    frame.add(taskField);
    frame.add(skillLabel);
    frame.add(skillField);
    frame.add(levelLabel);
    frame.add(levelField);
    frame.add(addButton);
    
    JButton showContentsButton = new JButton("Show Current Tasks");
    showContentsButton.addActionListener(e -> {
        JTextArea textArea = new JTextArea(10, 30);
        JScrollPane scrollPane = new JScrollPane(textArea);
        textArea.setEditable(false);

        try (BufferedReader br = new BufferedReader(new FileReader("tasks.txt"))) {
            String line;
            while ((line = br.readLine()) != null) {
                textArea.append(line + "\n");
            }
        } catch (IOException ex) {
            ex.printStackTrace();
        }

        JOptionPane.showMessageDialog(frame, scrollPane);
    });

    frame.add(showContentsButton);
    frame.setVisible(true);

  
}

public void displayMatchingForm() 
{
    frame.getContentPane().removeAll();
    frame.repaint();

    JLabel matchTypeLabel = new JLabel("Matching Type:");
    JRadioButton exactMatch = new JRadioButton("Exact Match");
    JRadioButton skillOnlyMatch = new JRadioButton("Skill-only Match");
    ButtonGroup group = new ButtonGroup();
    group.add(exactMatch);
    group.add(skillOnlyMatch);

    JButton generateButton = new JButton("Generate");
    JTextArea textArea = new JTextArea(10, 30);
    JScrollPane scrollPane = new JScrollPane(textArea);
    textArea.setEditable(false);
    
    generateButton.addActionListener(e -> {
        textArea.setText(""); 
        List<Resource> resources = loadResourcesFromFile();
        List<Task> tasks = loadTasksFromFile();

        if (exactMatch.isSelected()) {
            for (Task task : tasks) {
                for (Resource resource : resources) {
                    boolean isMatched = true;
                    for (Map.Entry<Skill, Character> entry : task.getRequiredSkills().entrySet()) {
                        Skill requiredSkill = entry.getKey();
                        char level = entry.getValue();
                        int minimumExperience = getMinimumExperienceForLevel(level);
                        boolean hasSkill = resource.getSkills().stream().anyMatch(
                            rSkill -> rSkill.getName().equals(requiredSkill.getName()) && 
                                      rSkill.getExperience() >= minimumExperience);
                        if (!hasSkill) {
                            isMatched = false;
                            break;
                        }
                    }
                    if (isMatched) {
                        textArea.append("Matched " + resource.getName() + " to task " + task.getName() + "\n");
                    }
                }
            }
        } else if (skillOnlyMatch.isSelected()) {
            for (Task task : tasks) {
                for (Resource resource : resources) {
                    boolean isMatched = true;
                    for (Skill requiredSkill : task.getRequiredSkills().keySet()) {
                        boolean hasSkill = resource.getSkills().stream().anyMatch(
                            rSkill -> rSkill.getName().equals(requiredSkill.getName()));
                        if (!hasSkill) {
                            isMatched = false;
                            break;
                        }
                    }
                    if (isMatched) {
                        textArea.append("Matched " + resource.getName() + " to task " + task.getName() + "\n");
                    }
                }
            }
        }
    });

    frame.setLayout(new FlowLayout());
    frame.add(matchTypeLabel);
    frame.add(exactMatch);
    frame.add(skillOnlyMatch);
    frame.add(generateButton);
    frame.add(scrollPane);

    frame.setVisible(true);
}

private int getMinimumExperienceForLevel(char level) {
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


private static List<Resource> loadResourcesFromFile() {
    List<Resource> resources = new ArrayList<>();
    try (BufferedReader br = new BufferedReader(new FileReader("applicants.txt"))) {
        String line;
        while ((line = br.readLine()) != null) {
            String[] parts = line.split("\\|");
            String name = parts[0].trim();
            Resource resource = new Resource(name);

            for (String skillData : parts[1].split(",")) {
                String[] skillParts = skillData.split(":");
                String skillName = skillParts[0].trim();
                int experience = Integer.parseInt(skillParts[1].trim());
                Skill skill = new Skill(skillName, experience); 
                resource.addSkill(skill);
            }

            resources.add(resource);
        }
    } catch (IOException e) {
        e.printStackTrace();
    }
    return resources;
}


private static List<Task> loadTasksFromFile() {
    List<Task> tasks = new ArrayList<>();
    try (BufferedReader br = new BufferedReader(new FileReader("tasks.txt"))) {
        String line;
        while ((line = br.readLine()) != null) {
            String[] parts = line.split("\\|"); 
if(parts.length < 2) {
    System.err.println("Skipping malformed line: " + line);
    continue;
}
String taskName = parts[0].trim();

            Task task = new Task(taskName);

            for (String skillData : parts[1].split(",")) {
                String[] skillParts = skillData.split(":");
                String skillName = skillParts[0].trim();
                char level = skillParts[1].trim().charAt(0); 
                Skill skill = new Skill(skillName); 
                task.addRequiredSkill(skill, level);
            }

            tasks.add(task);
        }
    } catch (IOException e) {
        e.printStackTrace();
    }
    return tasks;
}



    private static void saveResourcesToFile(List<Resource> resources) {
        try (BufferedWriter bw = new BufferedWriter(new FileWriter("applicants.txt", true))) {
            for (Resource resource : resources) {
                String line = resource.getName() + " | ";
                List<String> skills = resource.getSkills().stream()
                    .map(skill -> skill.getName() + ":" + skill.getExperience())
                    .collect(Collectors.toList());
                line += String.join(",", skills);
                bw.write(line);
                bw.newLine();
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

  private static void saveTasksToFile(List<Task> tasks) {
    try (BufferedWriter bw = new BufferedWriter(new FileWriter("tasks.txt", true))) {
        for (Task task : tasks) {
            String line = task.getName() + " | ";
            List<String> requiredSkills = task.getRequiredSkills().entrySet().stream()
                .map(entry -> entry.getKey().getName() + ":" + entry.getValue())
                .collect(Collectors.toList());
            line += String.join(",", requiredSkills);
            bw.write(line);
            bw.newLine();
        }
    } catch (IOException e) {
        e.printStackTrace();
    }
}
}

public class MainMenu {
    public static void main(String[] args) {
        JFrame frame = new JFrame("Resource / Task Allocation System");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(400, 200);
        frame.setLayout(new FlowLayout());

        JButton btnManageResources = new JButton("Manage Resources");
        JButton btnManageTasks = new JButton("Manage Tasks");
        JButton btnMatchResources = new JButton("Match Resources to Tasks");

        btnManageResources.addActionListener(e -> {
            AllocationGUI resourcesGUI = new AllocationGUI();
            resourcesGUI.displayResourceForm();
        });

        btnManageTasks.addActionListener(e -> {
            AllocationGUI tasksGUI = new AllocationGUI();
            tasksGUI.displayTaskForm();
        });

        btnMatchResources.addActionListener(e -> {
            AllocationGUI matchGUI = new AllocationGUI();
            matchGUI.displayMatchingForm();
        });

        frame.add(btnManageResources);
        frame.add(btnManageTasks);
        frame.add(btnMatchResources);
        frame.setVisible(true);
    }
}

