public class LinearSearch{
    public static void main(String[] args) {
        int[] nums ={23,345,56,368,67,35,90,75};
        int target = 75 ;
        int ans = search(nums, target);
        System.out.println(ans);
    }

    //Search in the array : return the index if item found
    //otherwise if item not found return -1
    static int search(int[] arr , int target){
        if (arr.length == 0){
            return -1 ;
        }
        //run a for loop
        for (int index = 0;index < arr.length; index++){
            //check for element
            int element = arr[index];
            if (element == target){
                return index;
            }

        }
        //none if the return statement above have executed ,hence the target not found
        return -1 ;
    }
}