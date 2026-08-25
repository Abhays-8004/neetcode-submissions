class Solution {
   public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>>adj;
        vector<int>indegree(numCourses,0);
        for(auto &edge:prerequisites){
            adj[edge[1]].push_back(edge[0]);
             indegree[edge[0]]++;
        }

        queue<int>q;
        for(int i= 0;i<numCourses;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        vector<int>ans;
        int finish = 0;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            ans.push_back(u);
            finish++;
            if(adj.count(u)){
                for(int v:adj[u]){
                indegree[v]--;
                if(indegree[v] == 0){
                    q.push(v);
                }
            }
            }
            
        }
        if(finish != numCourses){
            return {};
        }
        return ans;
    }
};
