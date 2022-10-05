import java.util.*;

public class Main {

  public static int[] nextGreater(int[] arr, int n) {
    int[] ans = new int[n];
    Arrays.fill(ans, -1);
    Stack<Integer> st = new Stack<>();
    // for(int i=0; i<n; i++) {
    //   if(st.empty() || arr[st.peek()] > arr[i]) { // stack empty || current ele is smaller than prev -> insert
    //     st.push(i);
    //   } else {
    //     while(!st.empty() && arr[st.peek()] < arr[i]) { // larger element found
    //       ans[st.pop()] = arr[i];
    //     }
    //     st.push(i);
    //   }
    // }
      // ===== better way to write above block ========
    for(int i=0; i<n; i++) {
        while(!st.empty() && arr[st.peek()] < arr[i]) { // larger element found
          ans[st.pop()] = arr[i];
        }
        st.push(i);
    }
    return ans;
  }

  public static void main(String[] args) {
    int[] arr = {4,3,2,7,8,1,9,10};
    int[] ans = nextGreater(arr, arr.length);
    System.out.println(Arrays.toString(ans));
  }

}