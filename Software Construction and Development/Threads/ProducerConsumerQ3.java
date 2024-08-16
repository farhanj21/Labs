package org.example;
import java.util.LinkedList;
import java.util.Queue;
class SharedBuffer
{
    private final int capacity;
    private final Queue<Integer> buffer;

    public SharedBuffer(int capacity) {
        this.capacity = capacity;
        this.buffer = new LinkedList<>();
    }

    public synchronized void produce(int item) throws InterruptedException {
        while (buffer.size() == capacity) {
            wait();
        }

        buffer.offer(item);
        System.out.println("Produced: " + item);

        notify();
    }

    public synchronized int consume() throws InterruptedException {
        while (buffer.isEmpty()) {
            wait();
        }

        int item = buffer.poll();
        System.out.println("Consumed: " + item);

        notify();

        return item;
    }
}

class Producer implements Runnable {
    private SharedBuffer obj;

    public Producer(SharedBuffer obj) {
        this.obj = obj;
    }

    @Override
    public void run() {
        for (int i = 1; i <= 5; i++) {
            try {
                obj.produce(i);
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}

class Consumer implements Runnable {
    private SharedBuffer obj;

    public Consumer(SharedBuffer obj) {
        this.obj = obj;
    }

    @Override
    public void run() {
        for (int i = 1; i <= 5; i++) {
            try {
                int item = obj.consume();
                Thread.sleep(1500);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}

public class ProducerConsumerQ3 {
    public static void main(String[] args) {
        SharedBuffer obj = new SharedBuffer(2);

        Thread producerThread = new Thread(new Producer(obj), "Producer");
        Thread consumerThread = new Thread(new Consumer(obj), "Consumer");

        producerThread.start();
        consumerThread.start();

        try {
            producerThread.join();
            consumerThread.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}
