import org.example.Student;
import org.example.StudentDAO;
import org.junit.jupiter.api.*;
import org.mockito.*;
import static org.mockito.Mockito.*;
import java.sql.*;
import java.util.List;

class StudentDAOTest 
{

    @Mock
    private Connection conn;
    @Mock
    private PreparedStatement preparedStatement;
    @Mock
    private ResultSet rs;

    @InjectMocks
    private StudentDAO studentDAO;

    @BeforeEach
    void setUp() throws SQLException 
    {
        MockitoAnnotations.openMocks(this);
        when(conn.prepareStatement(any(String.class))).thenReturn(preparedStatement);
        when(preparedStatement.executeQuery()).thenReturn(rs);
    }

    @Test
    void testAddStudent() throws SQLException {
        Student student = new Student(0, "Farhan", 21);
        when(conn.prepareStatement(anyString())).thenReturn(preparedStatement);

        studentDAO.addStudent(student);

        verify(preparedStatement, times(1)).executeUpdate();
    }

    @Test
    void testAddStudentSQLException() throws SQLException 
    {
        Student student = new Student(0, "Farhan", 21);
        when(conn.prepareStatement(anyString())).thenThrow(SQLException.class);
        
        Assertions.assertThrows(SQLException.class, () -> {
            studentDAO.addStudent(student);
        });
    }

    @Test
    void testGetAllStudents() throws SQLException {
        when(rs.next()).thenReturn(true).thenReturn(false);
        when(rs.getInt("student_id")).thenReturn(1);
        when(rs.getString("student_name")).thenReturn("Farhan");
        when(rs.getInt("student_age")).thenReturn(21);

        List<Student> students = studentDAO.getAllStudents();

        Assertions.assertFalse(students.isEmpty());
        Assertions.assertEquals("Farhan", students.get(0).getStudentName());
    }

    @Test
    void testGetAllStudentsSQLException() throws SQLException {
        when(conn.prepareStatement(anyString())).thenThrow(SQLException.class);
        Assertions.assertThrows(SQLException.class, () -> {
            studentDAO.getAllStudents();
        });
    }
}
