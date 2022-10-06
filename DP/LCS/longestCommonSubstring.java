// Problem link:   https://practice.geeksforgeeks.org/problems/longest-common-substring1452/1


import java.util.*;

public class Main {
    
    public static int substring(String s1, String s2, int m, int n){
        int[][] dp = new int[m+1][n+1];
        
        for(int i=0; i<dp.length; i++){
            dp[i][0]=0;
        }
        
        for(int j=0; j<dp[0].length; j++){
            dp[0][j]=0;
        }
        
        int max = 0;
        
        for(int i=1; i<dp.length; i++){
            for(int j=1; j<dp[0].length; j++){
                if(s1.charAt(i-1)==s2.charAt(j-1)){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = 0;
                }
                max=Math.max(max, dp[i][j]);
            }
        }
        
        return max;
    }
    
    public static void main(String[] args) throws Exception {
        String s1 = "abcde";
        String s2 = "abfce";
        
        int m = s1.length();
        int n = s2.length();
        
        int ans = substring(s1, s2, m, n);
        System.out.println(ans);
    }
}


// OUTPUT :-  2
