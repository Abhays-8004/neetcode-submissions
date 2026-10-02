class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,bool>map;

        for(int i = 0;i<n;i++){
           map[nums[i]] = true;
        }

        int idx = 1;
        while(map.find(idx) != map.end()){
            idx++;
        }

        return idx;

    }
};