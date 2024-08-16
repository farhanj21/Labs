package org.example;
import java.sql.*;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.SQLException;

public class ResourceDAO
{
    public static boolean insertResource(Resource resource) {
        String insertPersonSql = "INSERT INTO Resources (name) VALUES (?)";
        String insertSkillSql = "INSERT INTO ResourceSkills (personID, skill, level) VALUES (?, ?, ?)";
        ResultSet rs = null;

        try (Connection conn = DBConnection.getConnection();
             PreparedStatement pstmtPerson = conn.prepareStatement(insertPersonSql, Statement.RETURN_GENERATED_KEYS)) {

            pstmtPerson.setString(1, resource.getName());
            int affectedRows = pstmtPerson.executeUpdate();

            if (affectedRows > 0) {
                rs = pstmtPerson.getGeneratedKeys();
                if (rs.next()) {
                    int personID = rs.getInt(1);
                    resource.setPersonID(personID);
                    for (Skill skill : resource.getSkills()) {
                        try (PreparedStatement pstmtSkill = conn.prepareStatement(insertSkillSql)) {
                            pstmtSkill.setInt(1, personID);
                            pstmtSkill.setString(2, skill.getName());
                            pstmtSkill.setString(3, String.valueOf(skill.getExperience()));
                            pstmtSkill.executeUpdate();
                        }
                    }
                    return true;
                }
            }

        } catch (SQLException ex) {
            ex.printStackTrace();
        } finally {
            if (rs != null) {
                try {
                    rs.close();
                } catch (SQLException e) {
                    e.printStackTrace();
                }
            }
        }
        return false;
    }



    public static List<Resource> listAllResourcesWithSkills() {
        List<Resource> resources = new ArrayList<>();
        String sql = "SELECT p.personID, p.name, s.skill, s.level " +
                "FROM Resources p " +
                "LEFT JOIN ResourceSkills s ON p.personID = s.personID";

        try (Connection conn = DBConnection.getConnection();
             Statement stmt = conn.createStatement();
             ResultSet rs = stmt.executeQuery(sql)) {

            Map<Integer, Resource> resourceMap = new HashMap<>();

            while (rs.next()) {
                int personID = rs.getInt("personID");
                Resource resource = resourceMap.get(personID);

                if (resource == null) {
                    String name = rs.getString("name");
                    resource = new Resource(personID, name);
                    resourceMap.put(personID, resource);
                }

                String skillName = rs.getString("skill");
                String experienceLevel = rs.getString("level");
                if (skillName != null && experienceLevel != null) {
                    Skill skill = new Skill(skillName, experienceLevel);
                    resource.addSkill(skill);
                }
            }

            resources.addAll(resourceMap.values());

        } catch (SQLException ex) {
            ex.printStackTrace();
        }

        return resources;
    }
    public boolean deleteResource(int personID)
    {
        String sqlDeleteSkills = "DELETE FROM ResourceSkills WHERE personID = ?";
        String sqlDeletePerson = "DELETE FROM Resources WHERE personID = ?";

        try (Connection conn = DBConnection.getConnection();
             PreparedStatement pstmtDeleteSkills = conn.prepareStatement(sqlDeleteSkills);
             PreparedStatement pstmtDeletePerson = conn.prepareStatement(sqlDeletePerson)) {

            pstmtDeleteSkills.setInt(1, personID);
            pstmtDeleteSkills.executeUpdate();

            pstmtDeletePerson.setInt(1, personID);
            int affectedRows = pstmtDeletePerson.executeUpdate();

            return affectedRows > 0;

        } catch (SQLException e) {
            e.printStackTrace();
        }
        return false;
    }

    public boolean updateResource(Resource resource, Skill skill) {
        String updateResourceSql = "UPDATE Resources SET name = ? WHERE personID = ?";
        String updateSkillSql = "UPDATE ResourceSkills SET skill = ?, level = ? WHERE personID = ?";

        try (Connection conn = DBConnection.getConnection();
             PreparedStatement updateResourceStmt = conn.prepareStatement(updateResourceSql);
             PreparedStatement updateSkillStmt = conn.prepareStatement(updateSkillSql)) {

            conn.setAutoCommit(false);

            updateResourceStmt.setString(1, resource.getName());
            updateResourceStmt.setInt(2, resource.getpersonID());
            int resourceUpdateCount = updateResourceStmt.executeUpdate();

            updateSkillStmt.setString(1, skill.getName());
            updateSkillStmt.setString(2, skill.getExperience());
            updateSkillStmt.setInt(3, resource.getpersonID());
            int skillUpdateCount = updateSkillStmt.executeUpdate();

            if (resourceUpdateCount == 1 && skillUpdateCount == 1) {
                conn.commit();
                return true;
            } else {
                conn.rollback();
                return false;
            }

        } catch (SQLException ex) {
            ex.printStackTrace();
            return false;
        } finally {

        }
    }







}
