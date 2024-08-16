class Node<T> {
    T data;
    Node<T> next;

    public Node(T data) 
    {
        this.data = data;
        this.next = null;
    }
}

public class LL<T> 
{
    private Node<T> head;

    public LL() {
        this.head = null;
    }

    public void insertAtBeginning(T data) 
    {
        Node<T> nn = new Node<>(data);
        nn.next = head;
        head = nn;
    }

    public void insertAtEnd(T data) 
    {
        Node<T> nn = new Node<>(data);
        if (head == null) {
            head = nn;
            return;
        }

        Node<T> curr = head;
        while (curr.next != null) 
        {
            curr = curr.next;
        }
        curr.next = nn;
    }

    public void delete(T key) 
    {
        if (head == null) 
        {
            return;
        }

        if (head.data.equals(key)) 
        {
            head = head.next;
            return;
        }

        Node<T> curr = head;
        while (curr.next != null && !curr.next.data.equals(key)) 
        {
            curr = curr.next;
        }

        if (curr.next != null) {
            curr.next = curr.next.next;
        }
    }

    public void printList() {
        Node<T> curr = head;
        while (curr != null) 
        {
            System.out.print(curr.data + " ");
            curr = curr.next;
        }
        System.out.println();
    }

    public static void main(String[] args) {
        LL<Integer> intList = new LL<>();
        intList.insertAtBeginning(1);
        intList.insertAtEnd(3);
        intList.insertAtBeginning(0);
        intList.insertAtEnd(5);
        System.out.println("List before deleting:");
        intList.printList(); 
        intList.delete(1);
        System.out.println("List after deleting:");
        intList.printList();
    }
}
