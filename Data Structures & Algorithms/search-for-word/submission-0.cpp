class Solution {
public:
int n,m;
    vector<vector<int>>dir = {{1,0},{-1,0},{0,1},{0,-1}};
    bool dfs(int i, int j, vector<vector<char>>& board,
             string& word, int idx) {

        // Current character doesn't match
        if (board[i][j] != word[idx])
            return false;

        // Entire word matched
        if (idx == word.size() - 1)
            return true;

        // Mark current cell as visited
        char temp = board[i][j];
        board[i][j] = '#';

        for (auto &v : dir) {
            int i_new = i + v[0];
            int j_new = j + v[1];

            if (i_new >= 0 && i_new < n &&
                j_new >= 0 && j_new < m &&
                board[i_new][j_new] != '#') {

                if (dfs(i_new, j_new, board, word, idx + 1))
                    return true;
            }
        }

        // Unmark current cell
        board[i][j] = temp;

        return false;
    }


    bool exist(vector<vector<char>>& board, string word) {
         n = board.size();
         m = board[0].size();

        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(board[i][j] == word[0] ){
                    if(dfs(i,j,board,word,0)){
                        return true;
                    }
                }
            }
        }

        return false;
    }
};
