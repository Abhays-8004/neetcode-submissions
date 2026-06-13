class Solution {
public:
    int majorityElement(vector<int>& nums) {
       unordered_map<int,int>map;
       int ans = nums[0];
       for(int num:nums){
        map[num]++;
        if(map[ans]<map[num]){
            ans = num;
        }
       }

       return ans;
    }
};