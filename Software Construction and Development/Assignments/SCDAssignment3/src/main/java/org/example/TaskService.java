package org.example;

import java.util.List;
import java.util.Map;

public class TaskService {

    private final TaskDAO taskDAO;

    public TaskService() {
        this.taskDAO = new TaskDAO();
    }

    public boolean addTask(String name, Map<Skill, Character> requiredSkills) {
        Task newTask = new Task(name);
        //task.addRequiredSkill(new Skill(skill, ""), level);
        return taskDAO.insertTask(newTask);
    }

    public List<Task> getAllTasks() {
        return taskDAO.getAllTasksWithSkills();
    }

    public boolean updateTask(int taskId, String newName, Map<Skill, Character> newSkills) {
        Task updatedTask = new Task(taskId, newName);
       // updatedtask.addRequiredSkill(new Skill(skill, ""), level);
        return taskDAO.updateTask(updatedTask);
    }

    public boolean deleteTask(int taskId) {
        return taskDAO.deleteTaskById(taskId);
    }
}
