class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
      int n = nums.size();
      int i = 0;
      int j = 0;
      while(j<n){
        nums[i] = nums[j];
        while(j<n && nums[i]== nums[j]){
          j++;
        }
        i++;
      }
      return i;
    }
};