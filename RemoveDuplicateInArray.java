import java.util.Arrays;  
public class RemoveDuplicateInArray{  
public static int removeDuplicateElements(int arr[], int n){  
        if (n==0 || n==1){  
            return n;  
        }  
        int[] temp = new int[n];  
        int j = 0;  
        for (int i=0; i<n-1; i++){  
            if (arr[i] != arr[i+1]){  
                temp[j++] = arr[i];  
            }  
         }  
        temp[j++] = arr[n-1];     
        for (int i=0; i<j; i++){  
            arr[i] = temp[i];  
        }  
        return j;  
    }  
       
    public static void main (String[] args) {  
        int arr[] = {10,70,30,90,20,20,30,40,70,50}; 
        Arrays.sort(arr);
        int length = arr.length;  
        length = removeDuplicateElements(arr, length);    
        for (int i=0; i<length; i++)  
           System.out.print(arr[i]+" ");  
    }  
}  