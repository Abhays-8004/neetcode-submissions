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
    int countComponents(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        rank.resize(n,0);
        for(int i = 0;i<n;i++){
            parent[i] = i;
        }

        for(auto &edge:edges){
            if(find(edge[0]) == find(edge[1]))continue;
            else{
                unian(edge[0],edge[1]);
            }
        }

        int count = 0;
        for(int i = 0;i<n;i++){
            if(parent[i] == i){
                count++;
            }
        
        }

        return count;
    }
};
