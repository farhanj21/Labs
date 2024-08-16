package org.example;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.Socket;

public class Client {
    public static void main(String[] args) {
        try {
            Socket socket = new Socket("localhost", 12345);
            System.out.println("Connected to the server...");

            // Create a BufferedReader to read data from the server
            BufferedReader reader = new BufferedReader(new InputStreamReader(socket.getInputStream()));

            // Create a PrintWriter to send data to the server
            PrintWriter writer = new PrintWriter(socket.getOutputStream(), true);

            // Send a message to the server
            writer.println("Hello, server! This is the client.");

            // Receive and print the server's response
            String serverResponse = reader.readLine();
            System.out.println("Received from server: " + serverResponse);

            // Close the socket and streams
            reader.close();
            writer.close();
            socket.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
