class Solution {
public:
    vector<vector<int>>direction = {{-1,0},{1,0},{0,1},{0,-1}};
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int>>q;
        for(int  i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j] == 1){
                    q.push({i,j});
                    grid[i][j] = 2;
                    int perimeter= 0;
                    while(!q.empty()){
                        int N = q.size();
                        while(N--){
                            pair<int,int>temp = q.front();
                            q.pop();
                            int i = temp.first;
                            int j = temp.second;
                            
                            for(auto & dir:direction){
                                int x = i+dir[0];
                                int y = j+dir[1];
                                if(x<0 || x>=m || y<0 || y>=n || grid[x][y] == 0){
                                    perimeter++;
                                }else{
                                if(grid[x][y] != 2){
                                    q.push(make_pair(x,y));
                                    grid[x][y] = 2;
                                }
                                }
                            }
                        }
                    }

                    return perimeter;
                }
            }
        }
       
        

      return 0;  
    }
};