import java.util.Map;

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

