class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int count = 0;
        for(int i = 0;i<n;i++){
            if(nums[i] == val){
                count++;
            }
        }
        int i = 0;
        int  j = n-1;
        
        while(i<j){
            if(nums[i] == val){
                
                while(nums[j]== val){
                    
                    j--;
                }
                nums[i] = nums[j];
                j--;
            }
            i++;
        }

        

        return n-count;
    }
};