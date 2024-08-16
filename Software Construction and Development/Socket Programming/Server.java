package org.example;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;

public class Server {
    public static void main(String[] args) {
        try {
            ServerSocket serverSocket = new ServerSocket(12345);
            System.out.println("Server listening on port 12345...");

            while (true) {
                Socket clientSocket = serverSocket.accept();
                System.out.println("Client connected: " + clientSocket.getInetAddress());

                // Create a BufferedReader to read data from the client
                BufferedReader reader = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));

                // Create a PrintWriter to send data to the client
                PrintWriter writer = new PrintWriter(clientSocket.getOutputStream(), true);

                // Read data from the client
                String clientMessage = reader.readLine();
                System.out.println("Received from client: " + clientMessage);

                // Send a response back to the client
                writer.println("Hello, client! I received your message: " + clientMessage);

                // Close the sockets and streams
                reader.close();
                writer.close();
                clientSocket.close();
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
