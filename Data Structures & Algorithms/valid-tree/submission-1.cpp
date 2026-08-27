class Solution {
public:
     int find(int x,vector<int>&parent){
        if(x == parent[x]){
            return x;
        }
        
        return parent[x] = find(parent[x],parent);
    }
    
    void unian(int x,int y,vector<int>&parent,vector<int>&rank){
        int xparent = find(x,parent);
        int yparent = find(y,parent);
        
        if(xparent == yparent){
            return ;
        }
        if(rank[xparent]>rank[yparent]){
            parent[yparent] = xparent;
        }else if (rank[xparent]<rank[yparent]){
            parent[xparent] = yparent;
        }else{
            parent[xparent] = yparent;
            rank[yparent]+=1;
        }
        
        return;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
         vector<int>parent(n);
        vector<int>rank(n,0);
        
        for(int i = 0;i<n;i++){
            parent[i]= i;
        }

        vector<vector<int>>adj(n);
        for(auto &edge:edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        bool iscycle = false;
        for(int u= 0;u<n;u++){
            for(int &v:adj[u]){
                if(u<v){
                    int x = find(u,parent);
                    int y = find(v,parent);
                    if(x == y){
                        iscycle = true;
                    }
                    else{
                        unian(u,v,parent,rank);
                    }
                }
            }
        }

        int count = 0;
        for(int i = 0;i<n;i++){
            if(parent[i] == i){
                count++;
            }
        }

        if(count==1&&iscycle == false){
            return true;
        }

        return false;
    }
};
