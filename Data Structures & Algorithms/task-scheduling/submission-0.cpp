class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>mp(26,0);
        int times = 0;
        for(char &ch:tasks){
            mp[ch - 'A']++;
        }

        priority_queue<int>pq;

        for(int i = 0;i<26;i++){
            if(mp[i]>0){
                pq.push(mp[i]);
            }
        }

        while(!pq.empty()){
            vector<int>temp;
            for(int i = 1;i<=n+1;i++){
                if(!pq.empty()){
                    int fre = pq.top();
                    pq.pop();
                    fre--;
                    temp.push_back(fre);
                }

            }

            for(int &f:temp){
                if(f>0){
                    pq.push(f);
                }
                
            }

            if(pq.empty()){
                times += temp.size();
            }else{
                times += n+1;
            }
        }

        return times;
    }
};
