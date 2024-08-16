import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class JavaGUI 
{
    public static void main(String[] args) {
        SwingUtilities.invokeLater(new Runnable() {
            public void run() {
                firstGUI();
            }
        });
    }

    private static void firstGUI() 
    {
        JFrame frame = new JFrame("Hello, Swing!");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(400, 200);

        JButton clickMeButton = new JButton("Click Me");

        clickMeButton.addActionListener(new ActionListener() 
        {
            public void actionPerformed(ActionEvent e) 
            {
                JOptionPane.showMessageDialog(frame, "Hello, Swing!");
            }
        });

        frame.getContentPane().add(clickMeButton);

        frame.setLocationRelativeTo(null);

        frame.setVisible(true);
    }
}
