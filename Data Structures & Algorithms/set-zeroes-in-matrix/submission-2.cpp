class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        int m = matrix[0].size();
        vector<bool>rows(n,false);
        vector<bool>cols(m,false);

        for(int row= 0;row<n;row++){
            for(int col =0;col<m;col++){
                if(matrix[row][col] == 0){
                    rows[row] = true;
                    cols[col] = true;
                }
            }
        }

        for(int row = 0;row<n;row++){
            for(int col = 0;col<m;col++){
                if(rows[row] || cols[col]){
                    matrix[row][col] = 0;
                }
            }
        }

        
    }
};
