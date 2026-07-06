class Solution {
public:
    int trap(vector<int>& height) {
        
        int ans = 0;
        int l = 0;
        int r = height.size()-1;
        int lmax = height[l];
        int rmax = height[r];
        while(l<r){
            if(height[l]<height[r]){
                l++;
                lmax = max(lmax,height[l]);
                ans+= lmax- height[l];
            }else{
                r--;
                rmax = max(rmax,height[r]);
                ans+= rmax - height[r];
            }
        }
      
        return ans;
    }
};
