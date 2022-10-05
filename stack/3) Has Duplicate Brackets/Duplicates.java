import java.util.*;

public class Duplicates {

  public static boolean hasDuplicates(String str, int n) {
    Stack<Character> st = new Stack<>();
    char[] arr = str.toCharArray();
    for (char x : arr) {
      if (x == ')') {
        int cnt = 0;
        while (!st.empty() && st.peek() != '(') {
          if (st.peek() == '+' ||
              st.peek() == '-' ||
              st.peek() == '*' ||
              st.peek() == '/' ||
              st.peek() == '^') {
            cnt++;
          }
          st.pop();
        }
        if (cnt > 0 && st.peek() == '(')
          st.pop();
        else
          return true;
      } else
        st.push(x);
    }
    return !st.empty();
  }

  public static void main(String args[]) {
    String str = "((a)+(b+c))";
    System.out.print("hasDuplicates: " + hasDuplicates(str, str.length()));
  }
}