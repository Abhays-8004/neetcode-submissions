class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<int,vector<int>,greater<int>>minheap;
        for(int &v: nums){
            minheap.push(v);
            if(minheap.size()>k)
            {
                minheap.pop();
            }
        }

        return minheap.top();
    }
};
