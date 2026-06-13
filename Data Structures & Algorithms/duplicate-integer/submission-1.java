class Solution {
    public boolean hasDuplicate(int[] nums) {
        // Arrays.sort(nums);
        int n = nums.length;
        Set<Integer> hashset = new HashSet<>();

        for(int i = 0;i<n;i++){
            if(hashset.contains(nums[i])){
                return true;
            }else{
                hashset.add(nums[i]);
            }
        }

        return false;
    }
}