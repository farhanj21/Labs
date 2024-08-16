import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

class CSVReaderExample {
    static class Person {
        private String name;
        private int age;
        private String location;
        private int pf;
        private int scd;
        private double average;

        Person(String name, int age, String location, int pf, int scd) {
            this.name = name;
            this.age = age;
            this.location = location;
            this.pf = pf;
            this.scd = scd;
            this.average = (pf + scd) / 2.0;
        }
        void print() {
            System.out.println("-------------------------------");
            System.out.println("Name: " + name);
            System.out.println("Age: " + age);
            System.out.println("Location: " + location);
            System.out.println("PF: " + pf);
            System.out.println("SCD: " + scd);
            System.out.println("Average: " + average);
            System.out.println("-------------------------------");
        }


        String toCSVString()
        {
            return name + "," + age + "," + location + "," + pf + "," + scd + "," + average;
        }
    }

    static ArrayList<Person> loadFile(String fileName) {
        ArrayList<Person> list = new ArrayList<>();

        try (BufferedReader reader = new BufferedReader(new FileReader(fileName))) {
            String line;
            reader.readLine();

            while ((line = reader.readLine()) != null) {
                String[] parts = line.split(",");
                if (parts.length == 5) {
                    String name = parts[0];
                    int age = Integer.parseInt(parts[1]);
                    String location = parts[2];
                    int scd = Integer.parseInt(parts[3]);
                    int pf = Integer.parseInt(parts[4]);

                    Person newPerson = new Person(name, age, location, pf, scd);
                    list.add(newPerson);
                }
            }
        } catch (IOException e) {
            e.printStackTrace();
        }

        return list;
    }

    public static void main(String[] args) {
        String csvFileName = "Q4.csv";
        ArrayList<Person> list = loadFile(csvFileName);

        int count = list.size();
        int sumScd = 0;
        int sumPf = 0;



        for (Person person : list) {
            person.print();
        }



        File f= new File("Q4.csv");
        f.delete();

        try (FileWriter writer = new FileWriter("Q4.csv", true))
        {

            writer.write("Name,age,Location,SCD Marks,PF Marks,average\n");
            for (Person person : list) {
                writer.write(person.toCSVString() + "\n");
            }
            writer.flush();
        }
        catch (IOException e)
        {
            e.printStackTrace();
        }
    }
}