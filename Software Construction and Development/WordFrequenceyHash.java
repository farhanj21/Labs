import java.util.HashMap;

public class WordFrequencyCounter 
{
    public static void main(String[] args) {
        String text = "This is a sample text. This text contains sample words for counting words frequency.";
        
        String[] words = text.split("\\s+|\\p{Punct}");
        
        HashMap<String, Integer> wordFrequencyMap = new HashMap<>();

        for (String word : words) {
            if (!word.isEmpty()) 
            {
                word = word.toLowerCase();
                wordFrequencyMap.put(word, wordFrequencyMap.getOrDefault(word, 0) + 1);
            }
        }

        for (String word : wordFrequencyMap.keySet()) {
            int frequency = wordFrequencyMap.get(word);
            System.out.println(word + ": " + frequency);
        }
    }
}
