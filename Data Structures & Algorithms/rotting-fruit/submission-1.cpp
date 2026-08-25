class Solution {
public:
    vector<vector<int>>direction = {{1,0},{-1,0},{0,1},{0,-1}};
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        int n = grid.size();
        int m = grid[0].size();
        int fresh = 0;
        for(int i=0 ;i<n;i++){
            for(int j= 0;j<m;j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                }
                if(grid[i][j]== 1){
                    fresh++;
                }
            }
        }
        int ans=0;
        while(fresh>0 && !q.empty()){
            int t = q.size();
            for(int k = 0;k<t;k++){
                auto [u,v]= q.front();
                q.pop();

                for(auto &dir:direction){
                    int new_i = dir[0]+u;
                    int new_j = dir[1]+v;
                    if(new_i>=0&& new_i<n&& new_j>=0&&new_j<m && grid[new_i][new_j] == 1){  
                        q.push({new_i,new_j});
                        grid[new_i][new_j] = 2;
                        fresh--;
                    }
                }
            }
            ans++;
        }


       

        return fresh == 0?ans:-1;
    }
};
