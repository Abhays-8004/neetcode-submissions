class Solution {
    public int longestConsecutive(int[] nums) {
        int n =nums.length;

        Set<Integer> numset = new HashSet<>();
        for(int num:nums){
            numset.add(num);
        }
        int ans = 0;
        for(int num:numset){
            if(!numset.contains(num-1)){
                int length = 1;
                while(numset.contains(num + length)){
                    length++;
                }
                ans = Math.max(ans,length);
            }
        }

        return ans;
    }
}
