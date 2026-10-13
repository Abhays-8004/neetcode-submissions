class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
       
        int first = 0;
       int second= nums[0];

        for(int i = 2;i<=n;i++){
            int third = max(second,nums[i-1] + first);

            first = second;
            second = third;
        }

        return second;
    }
};
