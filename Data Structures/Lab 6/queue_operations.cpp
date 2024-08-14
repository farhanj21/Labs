int main()
{
int value;
Queue&lt;int&gt; queue;
queue.Enqueue(9);
queue.Enqueue(8);
queue.Enqueue(7);
queue.Dequeue(value);
queue.Enqueue(2);
queue.Dequeue(value);
queue.Enqueue(3);
queue.Dequeue(value);
queue.Enqueue(4);
queue.Dequeue(value);
queue.Enqueue(5);
queue.Dequeue(value);
queue.Dequeue(value);
queue.Enqueue(50);
queue.Enqueue(2);
queue.Enqueue(10);
queue.Display(); 
return 0;
}
