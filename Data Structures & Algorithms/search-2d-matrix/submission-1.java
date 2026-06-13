class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
                
        int i = 0;
        int j = matrix.length-1;
        int n = matrix[0].length;

        while(i<=j){
            int mid = i+ (j-i)/2;
            if(matrix[mid][0]<=target && target<= matrix[mid][n-1]){
                int s = 0;
                int e = n-1;
                while(s<= e){
                    int midx = s + (e - s)/2;

                    if(matrix[mid][midx] == target){
                        return true;
                    }else if(matrix[mid][midx] < target){
                        s = midx+1;
                    }else{
                        e = midx-1;
                    }
                }
                break;
            }else if(matrix[mid][0] > target){
                 j = mid -1;
            }else{ 
                i= mid +1;
            }
        }

        return false;
    }
}
