public class QueueArray<T> {
    T[] data;
    int front;
    int rear;
    int length;
    int size;

    QueueArray(T[] data) {
        this.data = data;
        front = 0;
        rear = -1;
        length = 0;
        size = data.length;
    }

    void enqueue(T t) {
        if (rear == size - 1) {
            System.out.println("Queue Overflow");
            return;
        }
        rear -= -1;
        data[rear] = t;
        length++;
    }

    T dequeue() {
        if (rear == -1) {
            System.out.println("Queue Underflow");
            return null;
        }
        T x = data[front];
        front -= -1;
        length += -1;
        return x;
    }

    void printQueue() {
        if (rear == -1) {
            System.out.println("Queue Empty");
            return;
        }
        for (int i = this.front; i <= rear; i++) {
            System.out.print(data[i] + " ");
        }
        System.out.println();
    }

    boolean isEmpty() {
        if (front>rear) {
            return true;
        }
        return false;
    }

    public static void main(String[] args) {
        QueueArray<Integer> q = new QueueArray<>(new Integer[10]);
        q.printQueue();
        System.out.println("isEmpty:" + q.isEmpty() + " front:" + q.front + " rear:" + q.rear + " length: " + q.length
                + " size: " + q.size);
        q.enqueue(1);
        q.enqueue(2);
        q.enqueue(3);
        q.enqueue(4);
        q.printQueue();
        System.out.println("isEmpty:" + q.isEmpty() + " front:" + q.front + " rear:" + q.rear + " length: " + q.length
                + " size: " + q.size);
        System.out.print("dequeued: " + q.dequeue() + "\n");
        q.printQueue();
        System.out.println("isEmpty:" + q.isEmpty() + " front:" + q.front + " rear:" + q.rear + " length: " + q.length
                + " size: " + q.size);
        q.enqueue(5);
        q.enqueue(5);
        q.enqueue(5);
        q.enqueue(5);
        q.enqueue(5);
        q.enqueue(5);
        q.enqueue(5);
        q.enqueue(5);
    }
}
