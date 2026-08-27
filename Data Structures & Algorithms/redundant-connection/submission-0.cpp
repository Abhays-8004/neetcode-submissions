class Solution {
public:
     vector<int>parent;
    vector<int>rank;
    int find(int x){
        if(x == parent[x]){
            return x;
        }
        return parent[x]= find(parent[x]);
    }

    void unian(int x,int y){
        int xparent = find(x);
        int yparent= find(y);
        if(xparent == yparent)return;
        if(rank[xparent]>rank[yparent]){
            parent[yparent] = xparent;
        }else if(rank[xparent]<rank[yparent]){
            parent[xparent] =  yparent;
        }else{
            parent[xparent] = yparent;
            rank[yparent]++;
        }

        return;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        parent.resize(n+1);
        rank.resize(n+1,0);
        for(int i = 0;i<n;i++){
            parent[i] = i;
        }

        vector<int>ans;
        for(auto &edge:edges){
            int uparent = find(edge[0]);
            int vparent = find(edge[1]);
            if(uparent== vparent){
                ans.push_back(edge[0]);
                ans.push_back(edge[1]);
            }else{
                unian(edge[0],edge[1]);
            }
        }


        return ans;
    }
};
