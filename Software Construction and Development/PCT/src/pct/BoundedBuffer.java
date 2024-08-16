/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package pct;

/**
 *
 * @author amyaw
 */
public class BoundedBuffer {
    
    int[] buffer;
    int capacity;
    int count;
    
    public BoundedBuffer(int c){
        capacity = c;
        buffer = new int[capacity];
        count = 0;        
    }
    
    public synchronized  void insert(int v){
        System.out.println("Inserting " + v);
        if (count < capacity){
            buffer[count] = v;
            count++;
        }
    }
    
    public synchronized int remove(){
        int v = Integer.MIN_VALUE;
        if (count > 0){
            count--;
            v = buffer[count];
            System.out.println("Removing " + v);            
        }
        return v;
    }
    
    public synchronized void display(){
        System.out.print("Buffer state:");
        for(int i=0; i < count; i++){
            System.out.print(buffer[i] + " ");
        }
        System.out.println();
    }
    
}
