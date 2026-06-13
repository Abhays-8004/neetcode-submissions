class Solution {
public:
int n;
int m ;
vector<vector<int>>direction = {{0,1},{0,-1},{1,0},{-1,0}};
int Bfs(int i,int j,vector<vector<int>>& grid){
    queue<pair<int,int>>q;
    q.push({i,j});
    grid[i][j] = 0;
    int count  =1;
    while(!q.empty()){
        int N = q.size();
        while(N--){
          pair<int,int>p = q.front();
           q.pop();
          int x = p.first;
          int y = p.second;
         for(auto & v:direction){
             int nx = x + v[0];
             int ny = y + v[1];
             if(nx>=0 && nx<m && ny>=0 && ny<n && grid[nx][ny] == 1){
                q.push(make_pair(nx,ny));
                grid[nx][ny] = 0;
                count++;
             }
            }
         
        }

    }

    return count;
}
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxarea = 0;
        m = grid.size();
        n = grid[0].size();
        
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j] == 1){
                    
                    maxarea = max(Bfs(i,j,grid),maxarea);
                }
            }
        }

        return maxarea;
    }
};
