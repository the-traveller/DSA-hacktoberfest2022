import java.util.*;

public class Main {

  public static int[] nextGreaterElement(int[] arr, int n) {
    int[] nge = new int[n]; // stores next greater element's index
    Arrays.fill(nge, n);
    Stack<Integer> st = new Stack<Integer>();
    for (int i = 0; i < n; i++) {
      while (!st.empty() && arr[st.peek()] < arr[i])
        nge[st.pop()] = i;
      st.push(i);
    }
    return nge;
  }

  public static void maxInWindow(int[] arr, int n, int k) {
    int[] nge = nextGreaterElement(arr, n);
    int[] ans = new int[n];
    for (int i = 0; i <= n - k; i++) {
      int j = i;
      while (nge[j] < i + k) { // 123456789
        j = nge[j];
      }
      ans[i] = arr[j];
    }
    System.out.println(Arrays.toString(ans));
  }

  public static void main(String[] args) {
    int[] arr = { 2, 1, 7, 3, 9, 6, 4, 5 };
    int k = 4;
    maxInWindow(arr, arr.length, k);  // [7, 9, 9, 9, 9, 0, 0, 0]
  }
}