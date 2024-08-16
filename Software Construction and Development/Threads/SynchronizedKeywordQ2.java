package org.example;

class SharedResource {
    private int count = 0;

    public synchronized void countIncrement() {
        count++;
        System.out.println(Thread.currentThread().getName() + ": Count value = " + count);
    }

    public int getCounter() {
        return count;
    }
}

class CountIncrement implements Runnable {
    private SharedResource obj;

    public CountIncrement(SharedResource obj) {
        this.obj = obj;
    }

    @Override
    public void run() {
        for (int i = 0; i < 5; i++) {
            obj.countIncrement();
        }
    }
}

public class SynchronizedKeywordQ2 {
    public static void main(String[] args) {
        SharedResource obj = new SharedResource();

        Thread thread1 = new Thread(new CountIncrement(obj), "Thread 1");
        Thread thread2 = new Thread(new CountIncrement(obj), "Thread 2");

        thread1.start();
        thread2.start();

        try {
            thread1.join();
            thread2.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        System.out.println("Final Count value: " + obj.getCounter());
    }
}
