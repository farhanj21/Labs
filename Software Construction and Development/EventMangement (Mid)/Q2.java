import javax.swing.*;
import java.awt.*;
import java.io.*;
import java.util.*;
import java.util.List;
class Event 
{
    int ID;
    String name, venue, from, to;
    List<Attendee> attendees = new ArrayList<>();

    public Event(int ID, String name, String venue, String from, String to) {
        this.ID = ID;
        this.name = name;
        this.venue = venue;
        this.from = from;
        this.to = to;
    }

    void add(Attendee attendee) {
        attendees.add(attendee);
    }

    void save() {
        if (isSlotAvailable()) {
            try (BufferedWriter writer = new BufferedWriter(new FileWriter("events.csv", true))) {
                writer.write(ID + "," + name + "," + venue + "," + from + "," + to);
                writer.newLine();
                for (Attendee participant : attendees) {
                    participant.save(ID);
                }
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }

    void display() {
        System.out.println("Event ID:" + ID + " Name:" + name);
        System.out.println("Venue: " + venue);
        System.out.println("Time Slot: " + from + " -> " + to);
        System.out.println("Attendees:");
        for (Attendee participant : attendees) {
            participant.display();
        }
    }

    boolean isSlotAvailable()
    {
        return true;
    }

    static void search(String criterion, String attribute) {

    }
}

class Attendee {
    int attenID;
    String name;

    public Attendee(int attenID, String name) {
        this.attenID = attenID;
        this.name = name;
    }

    void save(int ID) {
        try (BufferedWriter writer = new BufferedWriter(new FileWriter("attendees.csv", true))) {
            writer.write(attenID + "," + name + "," + ID);
            writer.newLine();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    void display() {
        System.out.println("Attendee ID: " + attenID);
        System.out.println("Name: " + name);
    }
}

public class EventForm 
{

    private JFrame frame;
    private JPanel panel;
    private JTextField nameField, fromField;
    private JTextField toField, venueField;
    private JTextArea attendeesArea;
    private JButton saveButton;

    public EventForm() {
        frame = new JFrame("Event Form");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(300, 300);

        panel = new JPanel();
        panel.setLayout(new BoxLayout(panel, BoxLayout.Y_AXIS));
        frame.add(panel);

        panel.add(createField("Name", nameField = new JTextField()));
        panel.add(createField("From", fromField = new JTextField()));
        panel.add(createField("To", toField = new JTextField()));
        panel.add(createField("Venue", venueField = new JTextField()));
        panel.add(createTextArea("Attendees: ", attendeesArea = new JTextArea()));

        saveButton = new JButton("Save");
        panel.add(saveButton);

        frame.pack();
        frame.setVisible(true);
    }

    private JPanel createField(String labelText, JTextField textField) {
        JPanel panel = new JPanel(new GridLayout(1, 2));
        JLabel label = new JLabel(labelText);
        panel.add(label);
        panel.add(textField);
        return panel;
    }

    private JPanel createTextArea(String labelText, JTextArea textArea) {
        JPanel panel = new JPanel(new BorderLayout());
        JLabel label = new JLabel(labelText);
        panel.add(label, BorderLayout.NORTH);
        JScrollPane scrollPane = new JScrollPane(textArea);
        panel.add(scrollPane, BorderLayout.CENTER);
        return panel;
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> new EventForm());
    }
}
