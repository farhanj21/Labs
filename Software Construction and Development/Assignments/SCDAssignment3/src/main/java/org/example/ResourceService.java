package org.example;
import java.util.List;

public class ResourceService
{

    private ResourceDAO resourceDAO;

    public ResourceService() {
        this.resourceDAO = new ResourceDAO();
    }

    public boolean addResource(Resource resource) {
        try {
            return resourceDAO.insertResource(resource);
        } catch (Exception e) {
            e.printStackTrace();
            return false;
        }
    }

    public List<Resource> getAllResourcesWithSkills() {
        try {
            return resourceDAO.listAllResourcesWithSkills();
        } catch (Exception e) {
            e.printStackTrace();
            return null;
        }
    }

    public boolean removeResource(int personID) {
        try {
            return resourceDAO.deleteResource(personID);
        } catch (Exception e) {
            e.printStackTrace();
            return false;
        }
    }

    public boolean modifyResource(int personID, Resource resource, Skill skill) {
        try {
            return resourceDAO.updateResource(resource, skill);
        } catch (Exception e) {
            e.printStackTrace();
            return false;
        }
    }

}
