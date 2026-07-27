class Solution {
public:
    void solve(vector<int>& candidates,vector<vector<int>>&ans,vector<int>result,int target,int sum,int idx){
        if(sum == target){
            ans.push_back(result);
            return;
        }
        if(sum>target||idx == candidates.size()){
            return;
        }

        result.push_back(candidates[idx]);
        solve(candidates,ans,result,target,sum+candidates[idx],idx+1);
        result.pop_back();
        while(idx+1<candidates.size() && candidates[idx] == candidates[idx+1]){
            idx++;
        }
        solve(candidates,ans,result,target,sum,idx+1);
        

    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>result;
        sort(candidates.begin(),candidates.end());
        int n = candidates.size();
       solve(candidates,ans,result,target,0,0);

        return ans;
    }
};
