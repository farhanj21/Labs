import java.io.*;
import java.util.*;

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
            try (BufferedWriter eventWriter = new BufferedWriter(new FileWriter("events.csv", true))) {
                eventWriter.write(ID + "," + name + "," + venue + "," + from + "," + to);
                eventWriter.newLine();
                for (Attendee attendee : attendees) {
                    attendee.save(ID);
                }
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }

    void display() {
        System.out.println("EventID:" + ID + " Name:" + name + " Venue: " + venue);
        System.out.println("Slot: " + from + " -> " + to);
        System.out.println("Attendees:");
        for (Attendee attendee : attendees) {
            attendee.display();
        }
    }
    
       boolean isSlotAvailable() {
        List<Event> allEvents = loadAllEvents();
        for (Event otherEvent : allEvents) {
            if (!this.equals(otherEvent) && this.venue.equals(otherEvent.venue)) {
                if ((this.from.compareTo(otherEvent.to) < 0) && (this.to.compareTo(otherEvent.from) > 0)) {
                    return false;
                }
            }
        }
        return true;
    }


        static void search(String criteria, String value) {
        List<Event> allEvents = loadAllEvents();
        switch (criteria) {
            case "name":
                for (Event event : allEvents) {
                    if (event.name.equals(value)) {
                        event.display();
                    }
                }
                break;
            case "attendee":
                for (Event event : allEvents) {
                    for (Attendee attendee : event.attendees) {
                        if (attendee.name.equals(value)) {
                            event.display();
                        }
                    }
                }
                break;
            case "venue":
                for (Event event : allEvents) {
                    for (Attendee attendee : event.attendees) {
                        if (attendee.name.equals(value)) {
                            event.display();
                        }
                    }
                }
                break;
            case "from":
                 for (Event event : allEvents) {
                    for (Attendee attendee : event.attendees) {
                        if (attendee.name.equals(value)) {
                            event.display();
                        }
                    }
                }
                
        }
    }

    static List<Event> loadAllEvents() {
        List<Event> allEvents = new ArrayList<>();
        try (BufferedReader reader = new BufferedReader(new FileReader("events.csv"))) {
            String line;
            while ((line = reader.readLine()) != null) {
                String[] parts = line.split(",");
                Event event = new Event(Integer.parseInt(parts[0]), parts[1], parts[2], parts[3], parts[4]);
                allEvents.add(event);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
        return allEvents;
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
        try (BufferedWriter attenWriter = new BufferedWriter(new FileWriter("attendees.csv", true))) {
            attenWriter.write(attenID + "," + name + "," + ID);
            attenWriter.newLine();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    void display() {
        System.out.println("AttendeeID: " + attenID + " Name: " + name);
    }
}

public class Main {
    public static void main(String[] args) 
    {
        Event e1 = new Event(1, "SOFTEC", "Lab 1", "8:00", "17:00");
        Event e2 = new Event(2, "CokeFest", "Royal Palm", "15:00", "19:00");

        
        Attendee a1 = new Attendee(1, "Ali");
        Attendee a2 = new Attendee(2, "Haris");
        
        e1.add(a1);
        e1.add(a2);

        e2.add(a1);

        e1.save();
        e2.save();

        e1.display();
        System.out.println("\n");
        e2.display();
        
       System.out.println("\n\n");
       Event.search("attendee", "Softec");
       System.out.println("After Searching for attendees in Softec: ");
       e1.display();
       Event.search("name", "Ali");
    }
}
