class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        vector<int> t(n + 1);

        //case 1 when you thefting from 0th house
        t[0] = 0;
        for(int i = 1;i<=n-1;i++){
            t[i] = max(t[i-1], nums[i-1] + (i-2>= 0?t[i-2]:0));
        }
        int result1 = t[n-1];

        //case 2 when you start thefting from 1st house
        t[1] = 0;
        for(int i = 2;i<=n;i++){
            t[i] = max(t[i-1], nums[i-1] + (i-2>= 0?t[i-2]:0));
        }
        
        int result2 = t[n];

        return max(result1,result2);

    }
};
