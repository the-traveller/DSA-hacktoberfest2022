// Problem link:   https://practice.geeksforgeeks.org/problems/longest-common-subsequence-1587115620/1


import java.util.*;

public class Main {
    
    public static int lcs(String s1, String s2, int m, int n){
        int[][] dp = new int[m+1][n+1];
        
        for(int i=0; i<dp.length; i++){
            dp[i][0]=0;
        }
        
        for(int j=0; j<dp[0].length; j++){
            dp[0][j]=0;
        }
        
        for(int i=1; i<dp.length; i++){
            for(int j=1; j<dp[0].length; j++){
                if(s1.charAt(i-1)==s2.charAt(j-1)){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=Math.max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        
        return dp[m][n];
    }
    
    public static void main(String[] args) throws Exception {
        String s1 = "abcdhlidgu";
        String s2 = "djkaygbkcslsiu";
        
        int m = s1.length();
        int n = s2.length();
        
        int ans = lcs(s1, s2, m, n);
        System.out.println(ans);
    }
}


// OUTPUT :-  6
