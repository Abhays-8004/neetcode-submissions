class Solution {
public:
    bool Dfs(unordered_map<int,vector<int>>&adj,vector<bool>&visited,vector<bool>&inrecursion,int u){
        visited[u] = true;
        inrecursion[u] = true;

        for(int v:adj[u]){
            if(!visited[v]){
                if(Dfs(adj,visited,inrecursion,v)){
                    return true;
                }
            }else if(inrecursion[v]){
                return true;
            }
        }

        inrecursion[u] = false;

        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>>adj;

        for(auto &edge:prerequisites){
            adj[edge[1]].push_back(edge[0]);
        }
        vector<bool>visited(numCourses,false);
        vector<bool>inrecursion(numCourses,false);

        for(int i =0;i<numCourses;i++){
            if(!visited[i] && Dfs(adj,visited,inrecursion,i)){
                return false;
            }
        }

        return true;
    }
};
