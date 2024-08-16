import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class CalculatorGUI {
    private JFrame frame;
    private JTextField textField;
    private String currInput = "";
    private double answer = 0;
    private char oper = ' ';

    public CalculatorGUI() {
        frame = new JFrame("Basic Calculator");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(400, 500);
        frame.setLayout(new BorderLayout());

        textField = new JTextField();
        textField.setEditable(false);
        textField.setHorizontalAlignment(JTextField.CENTER);
        frame.add(textField, BorderLayout.NORTH);
        Font answerFont = new Font("Times New Roman", Font.BOLD, 24);
        textField.setFont(answerFont);

        JPanel buttonPanel = new JPanel(new GridLayout(4, 4));
        frame.add(buttonPanel, BorderLayout.CENTER);

        String[] buttonLabels = {
                "7", "8", "9", "/",
                "4", "5", "6", "*",
                "1", "2", "3", "-",
                "0", "C", "=", "+"
        };

        Font buttonFont = new Font("Times New Roman", Font.BOLD, 20);

        for (String label : buttonLabels) {
            JButton button = new JButton(label);
            button.setFont(buttonFont);
            button.addActionListener(new ButtonClickListener());
            buttonPanel.add(button);
        }

        frame.setVisible(true);
    }

    private class ButtonClickListener implements ActionListener {
        public void actionPerformed(ActionEvent e) {
            String command = e.getActionCommand();

            if (Character.isDigit(command.charAt(0))) {
                currInput = currInput + command;
                textField.setText(currInput);
            } else if (command.equals("C")) {
                currInput = "";
                answer = 0;
                oper = ' ';
                textField.setText("");
            } else if (command.equals("=")) {
                if (oper != ' ') {
                    double operand = Double.parseDouble(currInput);
                    switch (oper) {
                        case '+':
                            answer = answer + operand;
                            break;
                        case '-':
                            answer = answer - operand;
                            break;
                        case '*':
                            answer = answer * operand;
                            break;
                        case '/':
                            if (operand != 0) {
                                answer = answer /  operand;
                            } else {
                                textField.setText("Error: Cannot divide by zero");
                                return;
                            }
                            break;
                    }
                    textField.setText(Double.toString(answer));
                    currInput = "";
                    oper = ' ';
                }
            } else {
                if (!currInput.isEmpty()) {
                    oper = command.charAt(0);
                    answer = Double.parseDouble(currInput);
                    currInput = "";
                }
            }
        }
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> new CalculatorGUI());
    }
}
