class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int>check;
        for(int i = 0;i<k;i++){
            if(check[nums[i]] > 0){
                return true;
            }
            check[nums[i]]++;
        }

        int i = 0;
        int j = k;
        while(j<nums.size()){
            
            if(check[nums[j]]>0){
                return true;
            }
            check[nums[i]]--;
            check[nums[j]]++;
            i++;
            j++;
        }


        return false;
    }
};