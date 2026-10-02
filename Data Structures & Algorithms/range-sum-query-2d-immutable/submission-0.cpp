class NumMatrix {
public:
    vector<vector<int>>mt;
    NumMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        mt.resize(n,vector<int>(m));
        for(int i = 0;i<n;i++){
            int sum = 0;
            for(int j = 0;j<m;j++){
               sum += matrix[i][j];
                mt[i][j] = sum;
                cout<<mt[i][j]<<" ";
            }
            cout<<endl;
        }
        
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        
        int ans = 0;
        for(int i = row1;i<=row2;i++){
            ans = ans + (col1 == 0?mt[i][col2]: (mt[i][col2] - mt[i][col1-1]));
        }

        return ans;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */