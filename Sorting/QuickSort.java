
import java.util.Arrays;

/* QuikSort  */
public class QuickSort{
    public static void main(String[] args) {
        int[] arr ={ 5,4,3,2,1 };
        sort(arr, 0, arr.length- 1);
        System.out.println(Arrays.toString(arr));
        
    }

    static void sort(int[] nums , int low, int high){
        if (low >= high){
            return;
        }
        int s =low;
        int e =high;
        int m =s+(e-s)/2;
        int pivot = nums[m];

        while( s<=e ){
            //It already Sorted if will not swap.
            while(nums[s]< pivot){
                s++;
            }
            while(nums[e] > pivot){
                e--;
            }
            if(s<=e){
                int temp =nums[s];
                nums[s] =nums[e];
                nums[e] =temp;
                s++;
                e--;
            }
        }
        sort(nums, low, e);
        sort(nums, s, high);
    }

}

import java.io.*;
  
class Sort {
  
    
    static void swap(int[] arr, int x, int y)
    {
        int temp = arr[x];
        arr[x] = arr[y];
        arr[y] = temp;
    }
  
  
    static int partition(int[] arr, int low, int high)
    {
  
      
        int pivot = arr[high];

        int x = (low - 1);
  
        for (int y = low; y <= high - 1; y++) {
  
      
            if (arr[y] < pivot) {
  
           
                x++;
                swap(arr, x, y);
            }
        }
        swap(arr, x + 1, high);
        return (x + 1);
    }
  

    static void quickSort(int[] arr, int low, int high)
    {
        if (low < high) {
  
            int pi = partition(arr, low, high);
  
            quickSort(arr, low, pi - 1);
            quickSort(arr, pi + 1, high);
        }
    }
  

    static void printArray(int[] arr, int size)
    {
        for (int x = 0; x < size; x++)
            System.out.print(arr[x] + " ");
  
        System.out.println();
    }
  
 
    public static void main(String[] args)
    {
        int[] arr = { 10, 7, 8, 9, 1, 5 };
        int n = arr.length;
  
        quickSort(arr, 0, n - 1);
        System.out.println("Sorted array: ");
        printArray(arr, n);
    }
}

