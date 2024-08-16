import org.junit.Test;
import static org.junit.Assert.*;

public class StringUtilsTest 
{
    private StringUtils str = new StringUtils();

    @Test
    public void testConcatenate() 
    {
        assertEquals("FarhanJafri", str.concatenate("Farhan", "Jafri"));
        assertEquals("testConcatenate", str.concatenate("test", "Concatenate"));
    }

    @Test(expected = IllegalArgumentException.class)
    public void testNullConcatenate() 
    {
        str.concatenate(null, "Jafri");
    }

    @Test
    public void testFindLength() 
    {
        assertEquals(6, str.findLength("Farhan"));
        assertEquals(0, str.findLength(""));
    }

    @Test(expected = IllegalArgumentException.class)
    public void testNullFindLength() 
    {
        str.findLength(null);
    }

    @Test
    public void testToUpperCase() 
    {
        assertEquals("FARHAN", str.toUpperCase("farhan"));
        assertEquals("JAFRI", str.toUpperCase("jafri"));
    }

    @Test(expected = IllegalArgumentException.class)
    public void testNullToUpperCase() 
    {
        str.toUpperCase(null);
    }
}
