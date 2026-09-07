class Trienode {
public:
    char data;
    Trienode* children[26];
    bool end;

    Trienode(char ch) {
        data = ch;
        end = false;

        for(int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
    }

    Trienode() {
        end = false;

        for(int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
    }
};


class Solution {
public:

    int n, m;

    vector<int> dr = {1, -1, 0, 0};
    vector<int> dc = {0, 0, 1, -1};

    Trienode* root = new Trienode();

    vector<vector<int>> visited;

    void insert(string word) {

        Trienode* curr = root;

        for(char ch : word) {

            int idx = ch - 'a';

            if(curr->children[idx] == NULL) {
                curr->children[idx] = new Trienode(ch);
            }

            curr = curr->children[idx];
        }

        curr->end = true;
    }


    void dfs(
        int i,
        int j,
        string s,
        vector<string>& result,
        vector<vector<char>>& board,
        Trienode* node
    ) {

        // Found a word
        if(node->end) {
            result.push_back(s);

            // Prevent duplicate answer
            node->end = false;
        }

        visited[i][j] = true;

        // Try all 4 directions
        for(int k = 0; k < 4; k++) {

            int newi = i + dr[k];
            int newj = j + dc[k];

            if(
                newi >= 0 &&
                newi < n &&
                newj >= 0 &&
                newj < m &&
                !visited[newi][newj]
            ) {

                int idx = board[newi][newj] - 'a';

                if(node->children[idx] != NULL) {

                    dfs(
                        newi,
                        newj,
                        s + board[newi][newj],
                        result,
                        board,
                        node->children[idx]
                    );
                }
            }
        }

        // Backtrack
        visited[i][j] = false;
    }


    vector<string> findWords(
        vector<vector<char>>& board,
        vector<string>& words
    ) {

        // Build Trie
        for(string word : words) {
            insert(word);
        }

        n = board.size();
        m = board[0].size();

        visited = vector<vector<int>>(
            n,
            vector<int>(m, false)
        );

        vector<string> result;

        for(int i = 0; i < n; i++) {

            for(int j = 0; j < m; j++) {

                int idx = board[i][j] - 'a';

                if(root->children[idx] != NULL) {

                    dfs(
                        i,
                        j,
                        string(1, board[i][j]),
                        result,
                        board,
                        root->children[idx]
                    );
                }
            }
        }

        return result;
    }
};