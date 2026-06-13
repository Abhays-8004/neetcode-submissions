class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
     int maxb = INT_MIN;
     for(int i = 0;i<n;i++){
        maxb = max(maxb,piles[i]);
     }

     int s = 1;
     int e = maxb;
     int ans;
     while(s<=e){
        int mid = (s+e)/2;
        int t = 0;
        for(int i = 0;i<n;i++){
            t += (piles[i]%mid ==  0? piles[i]/mid : piles[i]/mid + 1);
        }
        if(t<= h){
            ans = mid;
            e = mid-1;
        }else{
            s = mid+1;
        }
     }


     return ans;
    }
};