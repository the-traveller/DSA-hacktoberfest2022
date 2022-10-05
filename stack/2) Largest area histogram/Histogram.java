import java.util.*;

public class Histogram {

  public static void findNextSmaller(int[] arr, int[] ans, int n, String type) {
    Stack<Integer> st = new Stack<>();
    if(type.equals("NEXT")) {
      Arrays.fill(ans, n);
      for(int i=0; i<n; i++) {
        while(!st.empty() && arr[st.peek()] > arr[i]) {
          ans[st.pop()] = i;
        }
        st.push(i);
      }
    } else {
      Arrays.fill(ans, -1);
      for(int i=n-1; i>=0; i--) {
        while(!st.empty() && arr[st.peek()] > arr[i]) {
          ans[st.pop()] = i;
        }
        st.push(i);
      }
    }
  }

  public static int findLargestArea(int[] arr, int n) {
    int[] preSmaller = new int[n];
    int[] nextSmaller = new int[n];
    findNextSmaller(arr, preSmaller, n, "PREV");
    findNextSmaller(arr, nextSmaller, n, "NEXT");
    int maxArea = Integer.MIN_VALUE;
    for(int i=0; i<n; i++) {
      int curArea = (nextSmaller[i] - preSmaller[i] - 1) * arr[i];
      maxArea = Math.max(maxArea, curArea);
    }
    return maxArea;
  }

  public static void main(String[] args) {
    int[] arr = { 4, 2, 1, 5, 6, 3, 2, 4, 2 };
    int largestArea = findLargestArea(arr, arr.length);
    System.out.println("Largest area: " + largestArea);
  }

}
