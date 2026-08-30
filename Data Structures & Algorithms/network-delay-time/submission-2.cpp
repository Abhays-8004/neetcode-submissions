class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int,vector<pair<int,int>>>adj;

        for(auto edge:times){
            adj[edge[0]].push_back({edge[1],edge[2]});
        }
        vector<int>result(n+1,INT_MAX);

        set<pair<int,int>>st;
        st.insert({0,k});
        result[k] = 0;
        int time = 0;
        while(!st.empty()){
            auto &it = *st.begin();
            int node = it.second;
            int d= it.first;
            st.erase(it);
            for(auto &v:adj[node]){
                int adjnode = v.first;
                int dis = v.second;

                if(d+dis<result[adjnode]){
                    if(result[adjnode]!=INT_MAX){
                        st.erase({result[adjnode],adjnode});
                        
                    }
                    
                    result[adjnode] = dis+d;
                    st.insert({d+dis,adjnode});
                    
                    
                }
            }
        }

        for(int i = 1;i<n+1;i++){
            if(result[i] == INT_MAX){
                return -1;
            }else{
                time = max(time,result[i]);
            }
        }

        return time;
    }
};
