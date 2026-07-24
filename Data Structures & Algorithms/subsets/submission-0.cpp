class Solution {
public:

void solve(vector<int>& nums,vector<vector<int>>&ans,vector<int>&result,int idx){
    if(idx == nums.size()){
        ans.push_back(result);
        return;
    }

    ///when it has no choise
    result.push_back(nums[idx]);
    solve(nums,ans,result,idx+1);
    result.pop_back();
    
    solve(nums,ans,result,idx+1);
}
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>result = {};

        solve(nums,ans,result,0);
        return ans;
    }
};
