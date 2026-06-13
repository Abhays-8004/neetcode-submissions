class Solution {
public:
    // int dp[101];
    // int solve(vector<int>& nums,int  i ,int n){
    //     if(i >= n){
    //         return 0;
    //     }
    //     if(dp[i] != -1)return dp[-1];
    //     int take = nums[i] + solve(nums,i+2,n);
    //     int notTake = solve(nums,i+1,n);
        
    //     return dp[i] = max(take,notTake);
    // }
    int rob(vector<int>& nums) {
        if(nums.size() == 1){
            return nums[0];
        }
        int n = nums.size();
        int secondlast = 0;
        int last = 0;
        for(int i = 0;i<n;i++){
            int temp = max(secondlast + nums[i],last);
            secondlast = last ;
            last = temp;
        }
        // memset(dp,-1,sizeof(dp));
        // return solve(nums,0,nums.size());

        return last;
    }
};
