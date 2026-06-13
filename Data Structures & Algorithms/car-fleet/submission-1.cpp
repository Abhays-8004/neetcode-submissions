class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = speed.size();
        if(n==1){return 1;}
        vector<pair<int,int>>time(n);
        stack<int>s;
        

        for(int i = 0;i<n;i++){
            time[i]= {position[i],((target-position[i])*60)/speed[i]};
        }
        sort(time.begin(),time.end());
        for(int i = n-1;i>= 0;i--){
           if(!s.empty()){
             if(s.top()<time[i].second){
                s.push(time[i].second);
            }else{
                continue;
            }
           }else{
            s.push(time[i].second);
           }
        }

        return s.size();
    }
};
