import java.util.List;

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