class Solution {
public: 
    int n,m;
    vector<vector<int>>direction = {{1,0},{-1,0},{0,1},{0,-1}};

    void Dfs(int i ,int j,vector<vector<char>>& board){
        
        board[i][j]= '#';
        for(auto &dir:direction){
            int new_i = i+dir[0];
            int new_j = j+dir[1];
            if(new_i>=0 && new_i<n&& new_j>= 0 && new_j<m && board[new_i][new_j] == 'O'){
                Dfs(new_i,new_j,board);
            }
        }

        return;
    }

    void solve(vector<vector<char>>& board) {
        n = board.size();
        m = board[0].size();

        for(int i = 0;i<n;i++){
            if(board[i][0] == 'O'){
                Dfs(i,0,board);
            }

            if(board[i][m-1] == 'O'){
                Dfs(i,m-1,board);
            }
        }

        for(int i = 0;i<m;i++){
            if(board[0][i]== 'O'){
                Dfs(0,i,board);
            }
            if(board[n-1][i] == 'O'){
                Dfs(n-1,i,board);
            }
        }

        for(int i =  0;i<n;i++){
            for(int j = 0;j<m ;j++){
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
                if(board[i][j] == '#'){
                    board[i][j]  = 'O';
                }
            }
        }
    }
};
