class Solution {
public:
    int height(int node,unordered_map<int,vector<int>>&adj, vector<int>visited){
        queue<int>q;
        q.push(node);
        visited[node] = true;
        int h = -1;
        while(!q.empty()){
            int n = q.size();
            h++;
            for(int i = 0;i<n;i++){
                int u = q.front();
                q.pop();

                for(int v:adj[u]){
                    if(!visited[v]){
                        q.push(v);
                        visited[v] = true;
                    }
                }
            }
        }

        return h;
    }
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>>adj;
        for(auto &edge:edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<int>visited(n,false);
        unordered_map<int,vector<int>>result;
        int minHeight = INT_MAX;
        for(int i= 0;i<n;i++){
            int h = height(i,adj,visited);
            result[h].push_back(i);
            minHeight = min(minHeight,h);
        }

        return result[minHeight];
    }
};