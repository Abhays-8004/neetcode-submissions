class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        vector<bool>check(n+1);
        for(int x:nums){
            if(check[x-1]){
                return x;
            }else{
                check[x-1] = true;
            }
        }

        return 0;
    }
};
