public class StackArray<T> {
    T[] data;
    int length;
    int top;

    StackArray(T[] a) {
        data = a;
        length = a.length;
        top = -1;
    }

    public void push(T a) {
        if (top < length - 1) {
            top++;
            data[top] = a;
            return;
        }
        System.out.println("Stack Overflow");
    }

    public T pop() {
        if (top != -1) {
            top--;
            return data[top + 1];
        }
        System.out.println("Stack underflow");
        return null;
    }

    public boolean isEmpty() {
        if (top == -1) {
            return true;
        }
        ;
        return false;
    }

    public void printStack() {
        if (top == -1) {
            System.out.println("Stack is empty!");
            return;
        }
        for (int i = top; i > 0; i--) {
            System.out.print(data[i] + " ");
        }
        System.out.println();
    }

    public T peek() {
        return data[top];
    }

    public static void main(String[] args) {
        StackArray<Integer> s = new StackArray<>(new Integer[20]);
        System.out.println(s.isEmpty());
        s.push(2);
        s.push(3);
        s.push(4);
        s.push(5);
        s.push(6);
        s.push(7);
        System.out.println(s.isEmpty());
        s.printStack();
        System.out.println("top:" + s.peek());
        System.out.println("popped: " + s.pop());
        s.printStack();
    }
}
