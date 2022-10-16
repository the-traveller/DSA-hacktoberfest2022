import java.util.*;
//class Double ended queue
//class insert_at_first
//class insert_at_last
//class delete_element
//class display

class doublequeue{
    int front=-1,rear=-1;
    int queue[]=new int[10];
    void insert_at_first(int x){
        if(front==-1){
            front=rear=0;
            queue[front]=x;
        }
        else if(front==0){
            System.out.println("Queue is full");
        }
        else{
            front--;
            queue[front]=x;
        }
    }
    void insert_at_last(int x){
        if(front==-1){
            front=rear=0;
            queue[rear]=x;
        }
        else if(rear==9){
            System.out.println("Queue is full");
        }
        else{
            rear++;
            queue[rear]=x;
        }
    }
    void delete_element(){
        if(front==-1){
            System.out.println("Queue is empty");
        }
        else if(front==rear){
            front=rear=-1;
        }
        else{
            front++;
        }
    }
    //sort
    void sort(){
        int temp;
        for(int i=front;i<=rear;i++){
            for(int j=i+1;j<=rear;j++){
                if(queue[i]>queue[j]){
                    temp=queue[i];
                    queue[i]=queue[j];
                    queue[j]=temp;
                }
            }
        }
    }
    //search_element
    void search_element(int x){
        int flag=0;
        for(int i=front;i<=rear;i++){
            if(queue[i]==x){
                flag=1;
                break;
            }
        }
        if(flag==1){
            System.out.println("Element found");
        }
        else{
            System.out.println("Element not found");
        }
    }
    //replace_second_element
    void replace_second_element(int x){
        if(front==-1){
            System.out.println("Queue is empty");
        }
        else if(front==rear){
            System.out.println("Only one element is present");
        }
        else{
            queue[front+1]=x;
        }
    }
    

    void display(){
        if(front==-1){
            System.out.println("Queue is empty");
        }
        else{
            for(int i=front;i<=rear;i++){
                System.out.println(queue[i]);
            }
        }
    }
}
//main class
class DoubleEndedQueue{
    public static void main(String args[]){
        doublequeue dq=new doublequeue();
        Scanner sc=new Scanner(System.in);
        int ch,x;
        do{
            System.out.println("1.Insert at first");
            System.out.println("2.Insert at last");
            System.out.println("3.Delete element");
            System.out.println("4.Display");
            System.out.println("5.Sort");
            System.out.println("6.Search element");
            System.out.println("7.Replace second element");
            System.out.println("8.Exit");
            System.out.println("Enter your choice");
            ch=sc.nextInt();
            switch(ch){
                case 1:
                    System.out.println("Enter element to be inserted");
                    x=sc.nextInt();
                    dq.insert_at_first(x);
                    break;
                case 2:
                    System.out.println("Enter element to be inserted");
                    x=sc.nextInt();
                    dq.insert_at_last(x);
                    break;
                case 3:
                    dq.delete_element();
                    break;
                case 4:
                    dq.display();
                    break;
                case 5:
                    dq.sort();
                    break;
                case 6:
                    System.out.println("Enter element to be searched");
                    x=sc.nextInt();
                    dq.search_element(x);
                    break;
                case 7:
                    System.out.println("Enter element to be replaced");
                    x=sc.nextInt();
                    dq.replace_second_element(x);
                    break;
                case 8:
                    System.exit(0);
                    break;
                default:
                    System.out.println("Invalid choice");
            }
        }while(ch!=8);
    }
}