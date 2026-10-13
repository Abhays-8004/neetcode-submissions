#include <cstring>

class Solution {
public:
     
    
    int dp[101];
    int solve(int i,vector<int>& nums,int n){
        if(i>= n){
            return 0;
        }

        if(dp[i] != -1){
            return dp[i];
        }
        int steal = nums[i] + solve(i+2,nums,n);
        int skip = solve(i+1,nums,n);

        return dp[i] = max(steal,skip);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];

        memset(dp,-1,sizeof(dp));
        int ans1 = solve(0,nums,n-1);
        memset(dp,-1,sizeof(dp));
        int ans2 = solve(1,nums,n);

        return max(ans1,ans2);
    }
};
