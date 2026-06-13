class Solution {
    public int[] productExceptSelf(int[] nums) {
        int n = nums.length;
        int[] prfix = new int[n];
        int[] sufix = new int [n];
        prfix[0] = nums[0];
        sufix[n-1] = nums[n-1];
        for(int i = 1;i<n;i++){
            prfix[i] = nums[i] * prfix[i-1];
        }
        for(int i = n-2;i>=0;i--){
            sufix[i] = nums[i] * sufix[i+1];
        }

        int[] ans = new int[n];
        for(int i = 0;i<n;i++){
            ans[i] = (i-1>=0?prfix[i-1]:1) * (i+1<n?sufix[i+1]:1);
        }

        return ans;
    }
}  
