public class QueueLinkedList<T> { // linked list class
    // class contain one node and this node contains one node as a link to
    // another node in linkedlist
    Node head;
    int length;

    class Node {// Stucture of each node in linked List
        T data;
        Node next; // another node inside node this act as a link to another node

        Node() {
            data = null;
            next = null;
        }

        Node(T data) {
            this.data = data;
            next = null;
        }
    }

    QueueLinkedList() { // constructer to create first node at a time of object creation
        head = new Node();
        length = 0;
    }

    // adding new node to the last node in linkedlist
    void enqueue(T d) {
        Node newNode = new Node(d);
        Node temp = head;
        while (temp.next != null) {
            temp = temp.next;
        }
        temp.next = newNode;
        length++;
    }

    T dequeue() {
        if (this.head.next == null) {
            System.out.println("Queue underflow");
            return null;
        }
        T x = this.head.next.data;
        this.head.next = this.head.next.next;
        return x;
    }

    boolean isEmpty() {
        if (head.next == null) {
            return true;
        }
        return false;
    }

    void printQueue() {
        System.out.print("Queue: ");
        Node temp = head.next;
        if (temp == null) {
            System.out.println("Empty Queue");
            return;
        }
        while (temp != null) {
            System.out.print(temp.data + " ");
            temp = temp.next;
        }
        System.out.println();
    }

    public static void main(String[] args) {
        QueueLinkedList<Integer> q = new QueueLinkedList<>();// Object
        System.out.println("Queue Created.");

        // Traversing Queue initialy
        q.printQueue();
        System.out.println("length: " + q.length);
        System.out.println("Is Empty?: " + q.isEmpty());

        // Addind Elements in Queue
        q.enqueue(1);
        q.enqueue(2);
        q.enqueue(3);

        // Traversing Queue
        q.printQueue();
        System.out.println("length: " + q.length);
        System.out.println("Is Empty?: " + q.isEmpty());

        // Deleting from Queue
        System.out.println("dequeue: " + q.dequeue());
        q.printQueue();
    }
}
