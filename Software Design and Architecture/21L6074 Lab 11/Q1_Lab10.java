import java.util.LinkedList;
import java.util.Queue;

class PrintSpooler 
{
    private static PrintSpooler instance;
    private static Queue<String> printQueue = new LinkedList<>();

    private PrintSpooler() {}

    public static synchronized PrintSpooler getInstance() {
        if (instance == null) {
            instance = new PrintSpooler();
        }
        return instance;
    }

    public synchronized void addPrintJob(String job) {
        printQueue.add(job);
    }

    public synchronized void removePrintJob() {
        if (!printQueue.isEmpty()) {
            printQueue.remove();
        }
    }

    public synchronized void print() {
        while (!printQueue.isEmpty()) {
            String job = printQueue.peek();
            System.out.println("Printing job: " + job);
            printQueue.remove();
        }
    }
}
