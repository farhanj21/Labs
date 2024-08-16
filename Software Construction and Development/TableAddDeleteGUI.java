import javax.swing.*;
import javax.swing.table.DefaultTableModel;
import java.awt.event.*;

public class Q1 {

    private JFrame frame;
    private JTable table;
    private JTextField nameField;
    private JTextField priceField;
    private JTextField quantityField;
    private JLabel totalLabel;
    private DefaultTableModel model;
    private double totalPrice = 0;

    public Q1() {
        initializeGUI();
    }

    private void initializeGUI() {
        frame = new JFrame("Product List");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(500, 400);
        frame.setLayout(null);

        totalLabel = new JLabel("Total: 0.0");
        totalLabel.setBounds(10, 10, 200, 25);
        frame.add(totalLabel);

        initializeInputFields();

        initializeTable();

        frame.setVisible(true);
    }

    private void initializeTable() {
        String[] columns = {"Name", "Price", "Quantity", "Action"};
        model = new DefaultTableModel(columns, 0) {
            @Override
            public boolean isCellEditable(int row, int column) {
                return column == 3;
            }
        };

        table = new JTable(model);
        JScrollPane scrollPane = new JScrollPane(table);
        scrollPane.setBounds(10, 300, 460, 200);
        frame.add(scrollPane);

        table.addMouseListener(new MouseAdapter() {
            @Override
            public void mouseClicked(MouseEvent e) {
                int column = table.columnAtPoint(e.getPoint());
                int row = table.rowAtPoint(e.getPoint());
                if (column == 3) {
                    removeProduct(row);
                }
            }
        });
    }

    private void initializeInputFields() {
        nameField = new JTextField();
        nameField.setBounds(10, 50, 100, 25);
        frame.add(nameField);

        priceField = new JTextField();
        priceField.setBounds(120, 50, 100, 25);
        frame.add(priceField);
        quantityField = new JTextField();
        quantityField.setBounds(230, 50, 100, 25);
        frame.add(quantityField);

        JButton addButton = new JButton("Add to Cart");
        addButton.setBounds(340, 50, 130, 25);
        frame.add(addButton);

        addButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                addProduct();
            }
        });
    }

    private void addProduct() {
        String name = nameField.getText();
        double price = Double.parseDouble(priceField.getText());
        int quantity = Integer.parseInt(quantityField.getText());

        Object[] row = new Object[4];
        row[0] = name;
        row[1] = price;
        row[2] = quantity;
        row[3] = "x";

        model.addRow(row);

        totalPrice += price * quantity;
        totalLabel.setText("Total: " + totalPrice);
    }

    private void removeProduct(int rowIndex) {
        double price = (double) model.getValueAt(rowIndex, 1);
        int quantity = (int) model.getValueAt(rowIndex, 2);

        totalPrice -= price * quantity;
        totalLabel.setText("Total: " + totalPrice);

        model.removeRow(rowIndex);
    }

    public static void main(String[] args) {
        new Q1();
    }
}
