import org.example.MathOperations;
import org.junit.Test;
import static junit.framework.TestCase.assertEquals;
import static junit.framework.TestCase.fail;

public class MathOperationsTest {

    @Test
    public void testAddition() {
        MathOperations mathOperations = new MathOperations();
        int answer = mathOperations.add(5, 5);
        assertEquals(10, answer);
    }

    @Test
    public void testSubtraction() {
        MathOperations mathOperations = new MathOperations();
        int answer = mathOperations.subtract(5, 5);
        assertEquals(0, answer);
    }

    @Test
    public void testMultiplication() {
        MathOperations mathOperations = new MathOperations();
        int answer = mathOperations.multiply(5, 5);
        assertEquals(25, answer);
    }

    @Test
    public void testDivision() {
        MathOperations mathOperations = new MathOperations();
        int answer = mathOperations.divide(5, 5);
        assertEquals(1, answer);
    }

    @Test
    public void testDivisionByZero() {
        MathOperations mathOperations = new MathOperations();
        try {
            mathOperations.divide(5, 0);
            fail("Arithmetic Exception was not thrown");
        } catch (ArithmeticException e) {
            assertEquals("Cannot divide by zero", e.getMessage());
        }
    }
}
