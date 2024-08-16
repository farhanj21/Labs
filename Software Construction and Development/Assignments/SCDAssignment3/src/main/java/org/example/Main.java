package org.example;
import java.awt.FlowLayout;
import java.awt.GridLayout;
import javax.swing.*;
import java.io.*;
import java.util.*;

class Resource
{
    private String name;
    private List<Skill> skills = new ArrayList<>();
    int personID;

    public Resource(int personID, String name) {
        this.name = name;
        this.personID = personID;
    }

    public Resource(String name) {
        this.name = name;
    }

    public String getName() {
        return name;
    }
    public int getpersonID() {
        return personID;
    }

    public List<Skill> getSkills() {
        return skills;
    }


    public void addSkill(Skill skill) {
        skills.add(skill);
    }

    public void setPersonID(int personID) {
        this.personID = personID;

    }
    @Override
    public String toString()
    {
        StringBuilder sb = new StringBuilder();
        sb.append("ID: ").append(personID);
        sb.append(", ").append(name).append(" | ");

        for (Skill skill : skills) {
            sb.append(skill).append(", ");
        }
        return sb.toString();
    }

}

class Task
{
    private String name;
    int taskID;
    private Map<Skill, Character> requiredSkills = new HashMap<>();

    public Task(String name) {
        this.name = name;
    }

    public Task(int taskID, String name) {
        this.taskID = taskID;
        this.name = name;
    }

    public Task(int taskID, String name, Map<Skill, Character> requiredSkills) {
        this.taskID = taskID;
        this.name = name;
        this.requiredSkills = requiredSkills;

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

    public void setId(int taskId) {
        this.taskID = taskId;
    }

    public int getTaskID() {
        return taskID;
    }


    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append("ID: ").append(getTaskID()).append(", ");
        sb.append(name).append(" | ");
        for (Map.Entry<Skill, Character> entry : requiredSkills.entrySet()) {
            sb.append(entry.getKey().getName()).append(" : ").append(entry.getValue()).append(", ");
        }
        if (sb.length() > 0) {
            sb.setLength(sb.length() - 2);
        }
        return sb.toString();
    }


}

class Skill {
    private String name;
    private String experience;

    public Skill(String name, String experience) {
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

    public String getExperience() {
        return experience;
    }
    public String toString() {
        return name + " : " + experience;
    }
}


class AllocationGUI
{
    JFrame frame;
    ResourceService resourceService;
    TaskService taskService;

    public AllocationGUI() {
        frame = new JFrame("Resource / Task Allocation System");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(400, 300);
        resourceService = new ResourceService();
        taskService = new TaskService();
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
            String experience = expField.getText();

            Resource resource = new Resource(name);
            resource.addSkill(new Skill(skill, experience));

            if (resourceService.addResource(resource)) {
                JOptionPane.showMessageDialog(frame, "Resource Added!", "Success", JOptionPane.INFORMATION_MESSAGE);
            } else {
                JOptionPane.showMessageDialog(frame, "Failed to Add Resource", "Error", JOptionPane.ERROR_MESSAGE);
            }
        });

        JButton showContentsButton = new JButton("Show Current Resources");
        showContentsButton.addActionListener(e -> {
            JTextArea textArea = new JTextArea(10, 30);
            JScrollPane scrollPane = new JScrollPane(textArea);
            textArea.setEditable(false);

            List<Resource> resources = resourceService.getAllResourcesWithSkills();
            for (Resource resource : resources) {
                textArea.append(resource.toString() + "\n");
            }

            JOptionPane.showMessageDialog(frame, scrollPane, "Resource List", JOptionPane.INFORMATION_MESSAGE);
        });

        JButton deleteButton = new JButton("Delete Resource");
        deleteButton.addActionListener(e -> {
            String inputID = JOptionPane.showInputDialog(frame, "Enter ID of Resource to Delete:");
            if (inputID != null && !inputID.trim().isEmpty()) {
                try {
                    int personID = Integer.parseInt(inputID.trim());

                    if (resourceService.removeResource(personID)) {
                        JOptionPane.showMessageDialog(frame, "Resource Deleted!", "Success", JOptionPane.INFORMATION_MESSAGE);
                    } else {
                        JOptionPane.showMessageDialog(frame, "Failed to Delete Resource", "Error", JOptionPane.ERROR_MESSAGE);
                    }
                } catch (NumberFormatException ex) {
                    JOptionPane.showMessageDialog(frame, "Please enter a valid ID", "Error", JOptionPane.ERROR_MESSAGE);
                }
            }
        });

        JButton updateButton = new JButton("Update Resource");
        updateButton.addActionListener(e -> {
            String inputID = JOptionPane.showInputDialog(frame, "Enter ID of Resource to Update:");
            if (inputID != null && !inputID.trim().isEmpty()) {
                try {
                    int personID = Integer.parseInt(inputID.trim());

                    JTextField newNameField = new JTextField(15);
                    JTextField newSkillField = new JTextField(15);
                    JTextField newExpField = new JTextField(5);

                    JPanel panel = new JPanel(new GridLayout(0, 1));
                    panel.add(new JLabel("Resource Name:"));
                    panel.add(newNameField);
                    panel.add(new JLabel("Skill:"));
                    panel.add(newSkillField);
                    panel.add(new JLabel("Experience:"));
                    panel.add(newExpField);

                    int result = JOptionPane.showConfirmDialog(frame, panel, "Update Resource", JOptionPane.OK_CANCEL_OPTION);

                    if (result == JOptionPane.OK_OPTION) {
                        String newName = newNameField.getText();
                        String newSkill = newSkillField.getText();
                        String newExperience = newExpField.getText();

                        Resource updatedResource = new Resource(personID, newName);
                        Skill updatedSkill = new Skill(newSkill, newExperience);

                        boolean isUpdated = resourceService.modifyResource(personID, updatedResource, updatedSkill);

                        if (isUpdated)
                        {
                            JOptionPane.showMessageDialog(frame, "Resource Updated!", "Success", JOptionPane.INFORMATION_MESSAGE);
                        } else {
                            JOptionPane.showMessageDialog(frame, "Resource could not be Updated", "Error", JOptionPane.ERROR_MESSAGE);
                        }
                    }
                } catch (NumberFormatException ex) {
                    JOptionPane.showMessageDialog(frame, "Please enter a valid ID", "Error", JOptionPane.ERROR_MESSAGE);
                }
            }
        });

        frame.setLayout(new FlowLayout());
        frame.add(nameLabel);
        frame.add(nameField);
        frame.add(skillLabel);
        frame.add(skillField);
        frame.add(expLabel);
        frame.add(expField);
        frame.add(addButton);
        frame.add(deleteButton);
        frame.add(updateButton);
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
            Character level;
            try {
                level = levelField.getText().charAt(0);
            } catch (Exception ex) {
                JOptionPane.showMessageDialog(frame, "Enter valid level", "Error", JOptionPane.ERROR_MESSAGE);
                return;
            }

            Task task = new Task(taskName);
            task.addRequiredSkill(new Skill(skill, ""), level);

            TaskDAO dao = new TaskDAO();
            if (dao.insertTask(task)) {
                JOptionPane.showMessageDialog(frame, "Task Added!", "Success", JOptionPane.INFORMATION_MESSAGE);
            } else {
                JOptionPane.showMessageDialog(frame, "Failed to add task", "Error", JOptionPane.ERROR_MESSAGE);
            }
        });


        JButton showContentsButton = new JButton("Show Current Tasks");
        showContentsButton.addActionListener(e -> {
            JTextArea textArea = new JTextArea(10, 30);
            JScrollPane scrollPane = new JScrollPane(textArea);
            textArea.setEditable(false);

            List<Task> tasks = taskService.getAllTasks();

            for (Task task : tasks) {
                textArea.append(task.toString() + "\n");
            }

            JOptionPane.showMessageDialog(frame, scrollPane, "Task List", JOptionPane.INFORMATION_MESSAGE);
        });

        JButton deleteButton = new JButton("Delete Task");
        deleteButton.addActionListener(e -> {
            String inputID = JOptionPane.showInputDialog(frame, "Enter ID of Task to Delete:");
            if (inputID != null && !inputID.trim().isEmpty()) {
                try {
                    int taskId = Integer.parseInt(inputID.trim());
                    if (taskService.deleteTask(taskId)) {
                        JOptionPane.showMessageDialog(frame, "Task Deleted!", "Success", JOptionPane.INFORMATION_MESSAGE);
                    } else {
                        JOptionPane.showMessageDialog(frame, "Task could not be deleted. Make sure the ID is correct and the task exists.", "Error", JOptionPane.ERROR_MESSAGE);
                    }
                } catch (NumberFormatException ex) {
                    JOptionPane.showMessageDialog(frame, "Please enter a valid numeric Task ID", "Error", JOptionPane.ERROR_MESSAGE);
                }
            }
        });

        JButton updateButton = new JButton("Update Task");
        updateButton.addActionListener(e -> {
            String idInput = JOptionPane.showInputDialog(frame, "Enter ID of Task to Update:");
            if (idInput != null && !idInput.trim().isEmpty()) {
                try {
                    int taskID = Integer.parseInt(idInput.trim());

                    JTextField newTaskNameField = new JTextField(15);
                    JTextField newSkillNameField = new JTextField(15);
                    JTextField newSkillLevelField = new JTextField(1);

                    JPanel panel = new JPanel(new GridLayout(0, 1));
                    panel.add(new JLabel("Task Name:"));
                    panel.add(newTaskNameField);
                    panel.add(new JLabel("Skill Name:"));
                    panel.add(newSkillNameField);
                    panel.add(new JLabel("Skill Level:"));
                    panel.add(newSkillLevelField);

                    int result = JOptionPane.showConfirmDialog(frame, panel, "Update Task", JOptionPane.OK_CANCEL_OPTION);

                    if (result == JOptionPane.OK_OPTION) {
                        String newTaskName = newTaskNameField.getText();
                        Map<Skill, Character> skillsToUpdate = new HashMap<>();
                        String skillName = newSkillNameField.getText();
                        String skillLevelStr = newSkillLevelField.getText();
                        if (skillName.isEmpty() || skillLevelStr.isEmpty())
                        {
                            JOptionPane.showMessageDialog(frame, "Please enter both skill name and level", "Error", JOptionPane.ERROR_MESSAGE);
                            return;
                        }
                        char skillLevel = skillLevelStr.charAt(0);
                        skillsToUpdate.put(new Skill(skillName), skillLevel);
                        Task taskToUpdate = new Task(taskID, newTaskName, skillsToUpdate);

                        TaskDAO dao = new TaskDAO();
                        boolean isUpdated = dao.updateTask(taskToUpdate);

                        if (isUpdated) {
                            JOptionPane.showMessageDialog(frame, "Task Updated!", "Success", JOptionPane.INFORMATION_MESSAGE);
                        } else {
                            JOptionPane.showMessageDialog(frame, "Task could not be Updated", "Error", JOptionPane.ERROR_MESSAGE);
                        }
                    }
                } catch (NumberFormatException ex) {
                    JOptionPane.showMessageDialog(frame, "Please enter a valid Task ID", "Error", JOptionPane.ERROR_MESSAGE);
                } catch (StringIndexOutOfBoundsException ex) {
                    JOptionPane.showMessageDialog(frame, "Please enter a valid level", "Error", JOptionPane.ERROR_MESSAGE);
                }
            }
        });

        frame.setLayout(new FlowLayout());
        frame.add(taskLabel);
        frame.add(taskField);
        frame.add(skillLabel);
        frame.add(skillField);
        frame.add(levelLabel);
        frame.add(levelField);
        frame.add(addButton);
        frame.add(deleteButton);
        frame.add(updateButton);
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
            List<Resource> resources = ResourceDAO.listAllResourcesWithSkills();
            List<Task> tasks = TaskDAO.getAllTasksWithSkills();
            StringBuilder results = new StringBuilder();

            if (exactMatch.isSelected()) {
                for (Task task : tasks) {
                    for (Resource resource : resources) {
                        boolean isMatched = true;
                        for (Map.Entry<Skill, Character> entry : task.getRequiredSkills().entrySet()) {
                            Skill requiredSkill = entry.getKey();
                            char level = entry.getValue();
                            int minimumExperience = getMinimumExperienceForLevel(level);
                            boolean hasSkill = resource.getSkills().stream().anyMatch(
                                    rSkill -> rSkill.getName().equalsIgnoreCase(requiredSkill.getName()) &&
                                            Integer.parseInt(rSkill.getExperience()) >= minimumExperience

                            );
                            if (!hasSkill) {
                                isMatched = false;
                                break;
                            }
                        }
                        if (isMatched) {
                            textArea.append("Matched " + resource.getName() + " to task " + task.getName() + "\n");
                            String matchResult = "Matched " + resource.getName() + " to task " + task.getName() + "\n";
                            results.append(matchResult);
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
                            String matchResult = "Matched " + resource.getName() + " to task " + task.getName() + "\n";
                            results.append(matchResult);
                        }
                    }
                }
            }

            try {
                BufferedWriter writer = new BufferedWriter(new FileWriter("MatchedResults.txt"));
                writer.write(results.toString());
                writer.close();

                textArea.setText(results.toString());

                JOptionPane.showMessageDialog(frame, "Results Exported to MatchedResults.txt");
            } catch (IOException ioException) {
                JOptionPane.showMessageDialog(frame, "Error exporting results to file.");
                ioException.printStackTrace();
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

}

class MainMenu {
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

