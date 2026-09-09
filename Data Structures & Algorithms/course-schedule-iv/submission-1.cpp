class Solution {
public:

    bool Bfs(int u,int target,vector<bool>visited,unordered_map<int,vector<int>>&adj){

        queue<int>q;
        q.push(u);
        visited[u] = true;

        while(!q.empty()){
            int node = q.front();
            q.pop();
            if(node == target) return true;
            for(auto &v:adj[node]){
                if(!visited[v]){
                    q.push(v);
                    visited[v] = true;
                }
            }
        }

        return false;
    }
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        int n = queries.size();
        vector<bool>result(n);
        vector<bool>visited(numCourses,false);
        unordered_map<int,vector<int>>adj;
        for(auto &edge:prerequisites){
            adj[edge[0]].push_back(edge[1]);
        }

        for(int i = 0;i<n;i++){

            result[i] = Bfs(queries[i][0],queries[i][1],visited,adj);
        }

        return result;
    }
};