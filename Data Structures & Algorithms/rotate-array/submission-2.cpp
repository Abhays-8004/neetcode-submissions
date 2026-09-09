class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n =nums.size();
        for(int i = 0;i<n;i++){
            nums.push_back(nums[i]);
        }
        if(k>n){
            k = k%n;
        }
        vector<int>result;
        int j = n-k;
        for(int i = 0;i<n;i++){
            result.push_back(nums[j]);
            j++;
        }

        nums = result;
    }
};