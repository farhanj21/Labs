import java.util.Map;

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
