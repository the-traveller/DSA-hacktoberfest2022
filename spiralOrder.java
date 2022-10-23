class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        List<Integer> Res=new ArrayList<>();
        int rowBegin=0, rowEnd=matrix.length-1, colBegin=0, colEnd=matrix[0].length-1 ; 
        
        while(rowBegin<=rowEnd && colBegin<=colEnd){
            for(int i=colBegin;i<=colEnd;i++){
                Res.add(matrix[rowBegin][i]);
            }
            rowBegin++;
            
            for(int i=rowBegin;i<=rowEnd;i++){
                Res.add(matrix[i][colEnd]);
            }
            colEnd--;
            
            if(rowBegin<=rowEnd){
                for(int i=colEnd;i>=colBegin;i--){
                    Res.add(matrix[rowEnd][i]);
                }
                rowEnd--;    
            }
            
            if(colBegin<=colEnd){
                for(int i=rowEnd;i>=rowBegin;i--){
                    Res.add(matrix[i][colBegin]);
                }
                colBegin++;    
            }            
        }
        
        return Res;       
    }
}
