class Solution {
public:
    int n ;
    vector<int>dp;
    int solve(int i,vector<int>& nums){
        if(i>= n){
            return 0;
        }

        if(dp[i] != -1){
            return dp[i];
        }
        int steal = nums[i] + solve(i+2,nums);
        int skip = solve(i+1,nums);

        return dp[i] = max(steal,skip);
    }
    int rob(vector<int>& nums) {
        n = nums.size();
        dp.resize(101,-1);
        return solve(0,nums);
    }
};
