class Solution {
    public void setZeroes(int[][] matrix) {
        int n = matrix.length;
        int m = matrix[0].length;

       boolean[] rows = new boolean[n];

        boolean []cols = new boolean[m];

        for(int row= 0;row<n;row++){
            for(int col = 0;col<m;col++){
                if(matrix[row][col] == 0){
                    rows[row] = true;
                    cols[col] = true;
                }
            }
        }

        for(int row= 0;row<n;row++){
            for(int col = 0;col<m;col++){
                if(rows[row] || cols[col]){
                    matrix[row][col] = 0;
                }
            }
        }
    }
}
