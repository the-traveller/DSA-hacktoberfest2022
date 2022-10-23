import java.util.Scanner;

public class Krishnamurthy {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter a number");
        int n = sc.nextInt();
        int temp = n;
        int f =1 ,sum = 0;
        while (n>0)
        {
            for (int i = 1; i <=n%10 ; i++) {
                f *= i;
            }
            sum += f;
            n /= 10;
            f = 1;
        }
        if (sum == temp)
            System.out.println(temp+" is a Krishnamurthy Number");
        else System.out.println(temp+" is not a Krishnamurthy Number");
    }
}
