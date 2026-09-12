class Solution {
public:
        double Bfs(string node,string target, unordered_map<string,vector<pair<string,double>>>&adj,unordered_map<string,bool>visit){
            queue<pair<string,double>>q;
            q.push({node,1.0000});
            visit[node] = true;

            while(!q.empty()){
                auto [u,val] = q.front();
                q.pop();
                
                if(u == target){
                    return val;
                }
                for(auto v:adj[u]){
                    if(!visit[v.first]){
                        q.push({v.first,val*v.second});
                        visit[v.first] = true;
                    }
                    
                }
            }

         return -1.0000;
        }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,vector<pair<string,double>>>adj;

        unordered_map<string,bool>visit;

        for(int i = 0;i<values.size();i++){
            double x = 1/values[i];
            adj[equations[i][0]].push_back({equations[i][1],values[i]});
            adj[equations[i][1]].push_back({equations[i][0],x});
            visit[equations[i][0]] =false;
            visit[equations[i][1]] =false;
        }

        vector<double>result;
        for(auto &query:queries){
            if(!adj.count(query[0])){
                result.push_back(-1.0000);
                continue;
            }else{
                double x = Bfs(query[0],query[1],adj,visit);
                 result.push_back(x);
            }
            
        }

        return result;
    }
};