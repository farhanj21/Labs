package org.example;
import java.sql.*;
import java.util.ArrayList;
import java.util.List;
import java.util.Map;
public class TaskDAO {
    public boolean insertTask(Task task) {
        String insertTaskSQL = "INSERT INTO Tasks (name) VALUES (?)";
        String insertSkillSQL = "INSERT INTO TaskSkills (taskID, skill, level) VALUES (?, ?, ?)";

        Connection connection = null;
        PreparedStatement insertStatement = null;
        PreparedStatement insertSkillStmt = null;

        try {
            connection = DBConnection.getConnection();
            connection.setAutoCommit(false);

            insertStatement = connection.prepareStatement(insertTaskSQL, Statement.RETURN_GENERATED_KEYS);
            insertStatement.setString(1, task.getName());
            int affectedRows = insertStatement.executeUpdate();

            if (affectedRows == 0) {
                throw new SQLException("Inserting task failed, no rows affected.");
            }

            try (ResultSet generatedKeys = insertStatement.getGeneratedKeys()) {
                if (generatedKeys.next()) {
                    int taskId = generatedKeys.getInt(1);
                    insertSkillStmt = connection.prepareStatement(insertSkillSQL);
                    for (Map.Entry<Skill, Character> entry : task.getRequiredSkills().entrySet()) {
                        insertSkillStmt.setInt(1, taskId);
                        insertSkillStmt.setString(2, entry.getKey().getName());
                        insertSkillStmt.setString(3, entry.getValue().toString());
                        insertSkillStmt.addBatch();
                    }
                    insertSkillStmt.executeBatch();
                } else {
                    throw new SQLException("Creating task failed, no ID obtained.");
                }
            }
            connection.commit();
            return true;
        } catch (SQLException e) {
            if (connection != null) {
                try {
                    connection.rollback();
                } catch (SQLException ex) {
                    ex.printStackTrace();
                }
            }
            e.printStackTrace();
            return false;
        } finally {
            try {
                if (insertSkillStmt != null) insertSkillStmt.close();
                if (insertStatement != null) insertStatement.close();
                if (connection != null) {
                    connection.setAutoCommit(true);
                    connection.close();
                }
            } catch (SQLException ex) {
                ex.printStackTrace();
            }
        }
    }

    public static List<Task> getAllTasksWithSkills() {
        List<Task> tasks = new ArrayList<>();
        String selectTasksSQL = "SELECT * FROM Tasks";
        String selectSkillsSQL = "SELECT * FROM TaskSkills WHERE taskID = ?";

        try (Connection connection = DBConnection.getConnection();
             PreparedStatement selectTasksStmt = connection.prepareStatement(selectTasksSQL);
             ResultSet rsTasks = selectTasksStmt.executeQuery()) {

            while (rsTasks.next()) {
                int taskId = rsTasks.getInt("taskID");
                String name = rsTasks.getString("name");

                Task task = new Task(taskId, name);

                try (PreparedStatement selectSkillsStmt = connection.prepareStatement(selectSkillsSQL)) {
                    selectSkillsStmt.setInt(1, taskId);
                    try (ResultSet rsSkills = selectSkillsStmt.executeQuery()) {
                        while (rsSkills.next()) {
                            String skillName = rsSkills.getString("skill");
                            char level = rsSkills.getString("level").charAt(0);
                            Skill skill = new Skill(skillName);
                            task.addRequiredSkill(skill, level);
                        }
                    }
                }
                tasks.add(task);
            }

        } catch (SQLException e) {
            e.printStackTrace();
        }
        return tasks;
    }
    public boolean deleteTaskById(int taskId) {
        String deleteTaskSkillsSQL = "DELETE FROM TaskSkills WHERE taskID = ?";
        String deleteTaskSQL = "DELETE FROM Tasks WHERE taskID = ?";
        Connection connection = null;
        PreparedStatement deleteTaskSkillsStmt = null;
        PreparedStatement deleteTaskStmt = null;

        try {
            connection = DBConnection.getConnection();
            connection.setAutoCommit(false);

            deleteTaskSkillsStmt = connection.prepareStatement(deleteTaskSkillsSQL);
            deleteTaskSkillsStmt.setInt(1, taskId);
            deleteTaskSkillsStmt.executeUpdate();

            deleteTaskStmt = connection.prepareStatement(deleteTaskSQL);
            deleteTaskStmt.setInt(1, taskId);
            int affectedRows = deleteTaskStmt.executeUpdate();

            if (affectedRows == 0) {
                throw new SQLException("Deleting task failed, no rows affected.");
            }

            connection.commit();
            return true;
        } catch (SQLException e) {
            if (connection != null) {
                try {
                    connection.rollback();
                } catch (SQLException ex) {
                    ex.printStackTrace();
                }
            }
            e.printStackTrace();
            return false;
        } finally {
            try {
                if (deleteTaskSkillsStmt != null) deleteTaskSkillsStmt.close();
                if (deleteTaskStmt != null) deleteTaskStmt.close();
                if (connection != null) {
                    connection.setAutoCommit(true);
                    connection.close();
                }
            } catch (SQLException ex) {
                ex.printStackTrace();
            }
        }
    }

    public boolean updateTask(Task task) {
        String updateTaskSQL = "UPDATE Tasks SET name = ? WHERE taskID = ?";
        String deleteOldSkillsSQL = "DELETE FROM TaskSkills WHERE taskID = ?";
        String insertSkillSQL = "INSERT INTO TaskSkills (taskID, skill, level) VALUES (?, ?, ?)";

        Connection connection = null;
        PreparedStatement updateTaskStmt = null;
        PreparedStatement deleteOldSkillsStmt = null;
        PreparedStatement insertSkillStmt = null;

        try {
            connection = DBConnection.getConnection();
            connection.setAutoCommit(false);

            updateTaskStmt = connection.prepareStatement(updateTaskSQL);
            updateTaskStmt.setString(1, task.getName());
            updateTaskStmt.setInt(2, task.getTaskID());
            int affectedRows = updateTaskStmt.executeUpdate();

            if (affectedRows == 0) {
                throw new SQLException("Updating task failed, no rows affected.");
            }

            deleteOldSkillsStmt = connection.prepareStatement(deleteOldSkillsSQL);
            deleteOldSkillsStmt.setInt(1, task.getTaskID());
            deleteOldSkillsStmt.executeUpdate();

            insertSkillStmt = connection.prepareStatement(insertSkillSQL);
            for (Map.Entry<Skill, Character> entry : task.getRequiredSkills().entrySet()) {
                insertSkillStmt.setInt(1, task.getTaskID());
                insertSkillStmt.setString(2, entry.getKey().getName());
                insertSkillStmt.setString(3, entry.getValue().toString());
                insertSkillStmt.addBatch();
            }
            insertSkillStmt.executeBatch();

            connection.commit();
            return true;
        } catch (SQLException e) {
            if (connection != null) {
                try {
                    connection.rollback();
                } catch (SQLException ex) {
                    ex.printStackTrace();
                }
            }
            e.printStackTrace();
            return false;
        } finally {
            try {
                if (insertSkillStmt != null) insertSkillStmt.close();
                if (deleteOldSkillsStmt != null) deleteOldSkillsStmt.close();
                if (updateTaskStmt != null) updateTaskStmt.close();
                if (connection != null) {
                    connection.setAutoCommit(true);
                    connection.close();
                }
            } catch (SQLException ex) {
                ex.printStackTrace();
            }
        }
    }









}





