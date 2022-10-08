class Solution {
    public boolean isUgly(int n) {
        double x=n;
        int c=2, b=1;
        while(x>1 && c<=5){
            if(x%c==0){
                x=x/c;
            }
            else{
                c=c+b;
                b++;
            }
        }
        if(x==1)
            return true;
        else
            return false;
    }
}
