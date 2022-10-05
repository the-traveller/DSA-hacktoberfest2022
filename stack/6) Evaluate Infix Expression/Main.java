import java.util.*;

public class Main {

  public static HashMap<Character, Integer> precedence;

  Main() {
    precedence = new HashMap<>();
    precedence.put('+', 0);
    precedence.put('-', 0);
    precedence.put('*', 1);
    precedence.put('/', 1);
    precedence.put('^', 2);
  }

  public static double calc(double a, double b, char x) {
    if (x == '+')
      return a + b;
    else if (x == '-')
      return a - b;
    else if (x == '*')
      return a * b;
    else
      return a / b;
  }

  public static void solve(String str, int n) {
    char[] arr = str.toCharArray();
    Stack<Character> oprat = new Stack<>();
    Stack<Double> oprand = new Stack<>();
    for (char ele : arr) {
      if (Character.isDigit(ele)) {
        oprand.push(Double.parseDouble(ele + ""));
      } else {
        if (ele == '(')
          oprat.push(ele);
        else if (ele == ')') {
          while (!oprat.empty() && oprat.peek() != '(') {
            char symb = oprat.pop();
            double v2 = oprand.pop();
            double v1 = oprand.pop();
            double ans = calc(v1, v2, symb);
            oprand.push(ans);
          }
          oprat.pop();
        } else {
          while (!oprat.empty() && oprat.peek() != '(' && precedence.get(oprat.peek()) > precedence.get(ele)) {
            char symb = oprat.pop();
            double v2 = oprand.pop();
            double v1 = oprand.pop();
            double ans = calc(v1, v2, symb);
            oprand.push(ans);
          }
          oprat.push(ele);
        }
      }
    }
    while (!oprat.empty()) {
      char symb = oprat.pop();
      double v2 = oprand.pop();
      double v1 = oprand.pop();
      double ans = calc(v1, v2, symb);
      oprand.push(ans);
    }
    System.out.println("Ans: " + oprand.pop());
  }

  public static void main(String[] args) {
    new Main();
    String str = "1+2*(3/4)";
    solve(str, str.length());
  }
}