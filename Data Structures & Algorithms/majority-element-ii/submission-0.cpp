class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>map;
        for(int i = 0;i<n;i++){
            map[nums[i]]++;
        }
        vector<int>ans;
        for(auto m:map){
            if(m.second >(n/3)){
                ans.push_back(m.first);
            }
        }

        return ans;
    }
};