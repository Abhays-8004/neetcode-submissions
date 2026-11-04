#include<cstring>
class Solution {
public:
    int dp[101][101];
    int solve(int i,int j){
        if(i == 0 && j == 0)return 1;
        int top = 0,left = 0;
        if(dp[i][j] != -1)return dp[i][j];
        if(i>0){
            top = solve(i-1,j);
        }
        if(j>0){
            left= solve(i,j-1);
        }

        return dp[i][j] = left+top;
    }
    int uniquePaths(int m, int n) {
        memset(dp,-1,sizeof(dp));
        return solve(m-1,n-1);
    }
};
