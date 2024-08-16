import java.io.*;
import java.util.Scanner;

public class Encryption {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter a message to encrypt: ");
        String message = scanner.nextLine();

        String encryptedTEXT = encrypt(message, 3);
        System.out.println("Encrypted String: " + encryptedTEXT);

        writeFile("encrypted.txt", encryptedTEXT);
        System.out.println("Message encrypted and saved to 'encrypted.txt'.");

        System.out.print("Do you want to decrypt the message? (yes/no): ");
        String choice = scanner.nextLine().toLowerCase();
        
        if (choice.equals("yes")) {
            String encryptedText = readFile("encrypted.txt");
            String decryptedTEXT = decrypt(encryptedText, 3);
            System.out.println("Decrypted Message: " + decryptedTEXT);
        }

        scanner.close();
    }

    public static String encrypt(String text, int move) {
        StringBuilder res = new StringBuilder();

        for (char character : text.toCharArray()) {
            int ascii = (int) character;
            ascii += move;
            res.append((char) ascii);
        }

        return res.toString();
    }

    public static String decrypt(String text, int move) {
        StringBuilder res = new StringBuilder();

        for (char character : text.toCharArray()) {
            int ascii = (int) character;
            ascii -= move;
            res.append((char) ascii);
        }

        return res.toString();
    }

    public static void writeFile(String fname, String txt) {
        try {
            FileWriter writer = new FileWriter(fname);
            writer.write(txt);
            writer.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static String readFile(String fname) {
        StringBuilder txt = new StringBuilder();

        try {
            FileReader reader = new FileReader(fname);
            int c;
            while ((c = reader.read()) != -1) {
                txt.append((char) c);
            }
            reader.close();
        } catch (IOException e) {
            e.printStackTrace();
        }

        return txt.toString();
    }
}
