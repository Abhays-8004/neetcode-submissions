class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        if(m +n == n){
            for(int i = 0;i<n;i++){
                nums1[i] = nums2[i];
            }
        }else{
            for(int v:nums2){
                int i = m;
                while( i-1 >= 0 && nums1[i-1] > v){
                    nums1[i] = nums1[i-1];
                    i--;
                }
                nums1[i] = v;
                m++;
            }
        }
    }
};