class Solution {
public:
    typedef pair<int,int>p;
    int spanningTree(int V,vector<vector<p>>&adj) {
        // code here
       
        priority_queue<p,vector<p>,greater<p>>pq;
        vector<bool>visited(V,false);
        pq.push({0,0});
        int ans = 0;
        
        
        while(!pq.empty()){
            auto [dis,node] = pq.top();
            pq.pop();
            if(visited[node])continue;
            
            ans+=dis;
            visited[node] = true;
            for(auto &v:adj[node]){
                
                if(!visited[v.first]){
                    pq.push({v.second,v.first});
                }
            }
        }
        
        return ans;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<p>>adj(n);
        for(int i = 0;i<n-1;i++){
            for(int j= i+1;j<n;j++){
                int dis = abs(points[i][0] - points[j][0]) + abs(points[i][1]- points[j][1]);
                adj[i].push_back({j,dis});
                adj[j].push_back({i,dis});
            }
        }

        int ans = spanningTree(n,adj);

        return ans;
    }
};
