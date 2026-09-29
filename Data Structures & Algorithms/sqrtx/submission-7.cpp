class Solution {
public:
    int mySqrt(int x) {
        if(x == 0)return 0;
        if(x == 1)return 1;
        if(x == 2)return 1;

        int s= 0;
        int e = x/2;
        int ans=0;
        while(s<=e){
            int mid = s + (e-s)/2;
            long long sq = 1LL * mid * mid;
            if(sq >x){
                e = mid - 1;
                
            }else if(sq<x){
                
               ans = mid;
               s = mid+1;
            }else{
                return mid;
            }
        }
      return ans;  
    }
};