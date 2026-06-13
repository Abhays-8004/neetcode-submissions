class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)return nums[0];
        if(n == 2)return max(nums[0],nums[1]);
        int dp[n];
        
        for(int i = 0;i<=n-2;i++){
            int skip = i-1>=0 ? dp[i-1]:0;
            int steal = nums[i] + (i-2>=0? dp[i-2]:0);
            dp[i] = max(skip,steal);
        }

      int ans1 = dp[n-2];
      dp[0] = 0;
      for(int i = 1;i<=n-1;i++){
            int skip = dp[i-1];
            int steal = nums[i] + (i-2>=0? dp[i-2]:0);
            dp[i] = max(skip,steal);
        }

        int ans2 = dp[n-1];
        return max(ans1,ans2);
    }
};
