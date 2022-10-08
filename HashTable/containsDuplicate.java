import java.util.*;
class containsduplicate {
    public static boolean containsDuplicate(int[] nums) 
    {
        boolean f=false;
        if(nums==null || nums.length==0)
        {
            f=false;
        }
        HashSet<Integer> myset = new HashSet<Integer>();
        for(int i: nums)
        {
            if(myset.add(i)==false)
            {
                f=true;
            }
        }

        return f;
    }
    
    public static void main(String[] args)
    {
        int[] arr = { 10, 5, 3, 4, 3, 5, 6 };
        if (containsDuplicate(arr)==true) {
            System.out.print("Yes");
        }
        else {
            System.out.print("No");
        }
    }
}