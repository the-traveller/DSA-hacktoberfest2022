public class MinHeap<T extends Comparable<T>> {
    private T[] Heap;
    private int size;
    private int maxsize;

    private static final int FRONT = 1;

    public MinHeap(T[] arr,T node){
        this.maxsize = arr.length;
        this.size = 0;
        Heap = arr;
        Heap[0] =node;
    }

    private int parent(int pos){
        return pos/2;
    }
    private int leftChild(int pos){
        return pos*2;
    }
    private int rightChild(int pos){
        return (pos*2) + 1;
    }
    private boolean isLeaf(int pos){
        if(pos>= (size/2) && pos <= size){
            return true;
        }
        return false;
    }
    private void swap(int pos1,int pos2){
        T temp = Heap[pos1];
        Heap[pos1] = Heap[pos2];
        Heap[pos2] = temp;
    }

    public void print(){
        for(int i=1;(i<=size/2);i++){
            System.out.println("Parent: "+Heap[i] +" Left child: "+Heap[i*2]+" Right child: "+Heap[i*2+1]);
        }
    }

    private void minHeapify(int pos){
        if (!isLeaf(pos)) {
            if(Heap[pos].compareTo(Heap[leftChild(pos)])>0 || Heap[pos].compareTo(Heap[rightChild(pos)])>0){
                if(Heap[leftChild(pos)].compareTo(Heap[rightChild(pos)])<0){
                    swap(pos, leftChild(pos));
                    minHeapify(leftChild(pos));
                }else{
                    swap(pos, rightChild(pos));
                    minHeapify(rightChild(pos));
                }
            }
        }
    }
    
    public void insert(T element){
        if(size>=maxsize){
            return;
        }
        Heap[++size] = element;
        int current = size;

        while(Heap[current].compareTo(Heap[parent(current)])>0){
            swap(current, parent(current));
            current = parent(current);
        }
    }

    public T remove(){
        T popped = Heap[FRONT];
        Heap[FRONT] = Heap[size--];
        minHeapify(FRONT);
        return popped; 
    }

    public void minHeap(){
        for(int pos=(size/2);pos>=1;pos--){
            minHeapify(pos);
        }
    }

    public static void main(String[] args) {
        System.out.println("The min heap is: ");
        MinHeap<Integer> minHeap = new MinHeap<Integer>(new Integer[15], 5);
        // minHeap.print();
        //minHeap.insert(5);
        minHeap.insert(3);
        minHeap.insert(17);
        minHeap.insert(10);
        minHeap.insert(84);
        minHeap.insert(19);
        minHeap.insert(6);
        minHeap.insert(22);
        minHeap.insert(9);
        minHeap.minHeap();

        minHeap.print();
        System.out.println("The minimum value is: "+minHeap.remove());

    }
}
