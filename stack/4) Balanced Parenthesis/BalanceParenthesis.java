import java.util.*;

public class BalanceParenthesis {

  public static boolean isBalanced(String str, int n) {
    Stack<Character> st = new Stack<>();
    char[] arr = str.toCharArray();
    for(char x: arr) {
      if(x == '{' || x == '[' || x == '(') st.push(x);
      else if(x == '}' || x == ']' || x == ')') {
        if(st.empty()) return false;
        char top = st.peek();
        if((top=='[' && x==']') || (top=='{' && x=='}') || (top=='(' && x==')')) st.pop();
        else return false;
      }
    }
    return st.empty();
  }

  public static void main(String[] args) {
    String str = "[(a+b)-{c*d}]";
    boolean ans = isBalanced(str, str.length());
    System.out.println("is balanced: " + ans);
  }
}
