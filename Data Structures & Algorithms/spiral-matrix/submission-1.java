class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
     int left = 0;
     int right = matrix[0].length-1;
     int top = 0;
     int bottom = matrix.length-1; 
     ArrayList<Integer> arr = new ArrayList<>();

     while(left<=right && top<= bottom){
        for(int i = left;i<=right;i++){
            arr.add(matrix[top][i]);
        }
        for(int i = top+1;i<=bottom;i++){
            arr.add(matrix[i][right]);
        }
        if(top<bottom){
            for(int i = right-1;i>= left;i--){
            arr.add(matrix[bottom][i]);
        }
        }
        if(left<right){
            for(int i = bottom-1;i>=top+1;i--){
            arr.add(matrix[i][left]);
        }
        }
        

        left++;right--;top++;bottom--;
     }


     return arr; 
    }
}
