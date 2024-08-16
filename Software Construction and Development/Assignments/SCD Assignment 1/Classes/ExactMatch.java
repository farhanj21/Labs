import java.util.Map;

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
