class Solution {
public:
    void solve(vector<int>& nums, vector<int>& result,
               vector<vector<int>>& ans,
               int target, int sum, int idx) {

        if (sum == target) {
            ans.push_back(result);
            return;
        }

        if (sum > target)
            return;

        for (int i = idx; i < nums.size(); i++) {
            result.push_back(nums[i]);
            solve(nums, result, ans, target, sum + nums[i], i);
            result.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> result;

        solve(nums, result, ans, target, 0, 0);

        return ans;
    }
};