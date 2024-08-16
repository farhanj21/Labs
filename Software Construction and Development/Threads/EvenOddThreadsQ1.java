package org.example;

class EvenOddThreads implements Runnable {
    private static int count = 1;
    private static final Object lock = new Object();

    private boolean EvenThread;

    public EvenOddThreads(boolean EvenThread) {
        this.EvenThread = EvenThread;
    }

    @Override
    public void run() {
        while (count <= 10) {
            synchronized (lock) {
                if ((count % 2 == 0 && EvenThread) || (count % 2 != 0 && !EvenThread)) {
                    System.out.println(Thread.currentThread().getName() + ": " + count);
                    count++;
                    lock.notify();
                } else {
                    try {
                        lock.wait();
                    } catch (InterruptedException e) {
                        e.printStackTrace();
                    }
                }
            }
        }
    }
}

public class EvenOddThreadsQ1 {
    public static void main(String[] args) {
        EvenOddThreads evenPrinter = new EvenOddThreads(true);
        EvenOddThreads oddPrinter = new EvenOddThreads(false);

        Thread evenThread = new Thread(evenPrinter, "EvenThread");
        Thread oddThread = new Thread(oddPrinter, "OddThread");

        evenThread.start();
        oddThread.start();
    }
}
