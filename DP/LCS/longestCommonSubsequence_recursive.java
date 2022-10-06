import java.util.*;

public class Main {
    
    public static int lcs(String x, String y, int m, int n){
        if(m==0 || n==0){
            return 0;
        }
        else{
            if(x.charAt(m-1)==y.charAt(n-1)){
                return 1 + lcs(x, y, m-1, n-1);
            }
            else{
                return Math.max(lcs(x, y, m, n-1), lcs(x, y, m-1, n));
            }
        }
    }
    
    public static void main(String[] args) throws Exception {
        String x = "abcdefgh";
        String y = "zadgjefbngnh";
        
        int m = x.length();
        int n = y.length();
        
        int ans = lcs(x, y, m, n);
        System.out.println(ans);
    }
}


// OUTPUT :-  6
