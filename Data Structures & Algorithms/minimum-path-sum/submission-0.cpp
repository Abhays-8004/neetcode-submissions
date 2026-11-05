
class Solution {
public:
    int n, m;
    vector<vector<int>>dp;

    int solve(int i, int j, vector<vector<int>>& grid) {
        if (i == m - 1 && j == n - 1)
            return grid[i][j];

        int down = INT_MAX;
        int right = INT_MAX;

        if(dp[i][j] != -1)return dp[i][j];

        if (i + 1 < m) {
            down = grid[i][j] + solve(i + 1, j, grid);
        }

        if (j + 1 < n) {
            right = grid[i][j] + solve(i, j + 1, grid);
        }

        return dp[i][j] =  min(down, right);
    }

    int minPathSum(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        dp.assign(m,vector<int>(n,-1));

        return solve(0, 0, grid);
    }
};
