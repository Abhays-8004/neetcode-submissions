class Solution {
public:
    vector<vector<int>> direction = {
        {1, 0},
        {-1, 0},
        {0, -1},
        {0, 1}
    };

    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();

        // min-heap: {height, {x, y}}
        set<pair<int, pair<int, int>>> s;

        vector<vector<bool>> visited(n, vector<bool>(n, false));

        s.insert({grid[0][0], {0, 0}});
        visited[0][0] = true;

        int ans = 0;

        while (!s.empty()) {

            // Get the smallest height
            auto it = s.begin();

            int value = it->first;
            int x = it->second.first;
            int y = it->second.second;

            // Remove only this element
            s.erase(it);

            ans = max(ans, value);

            // We reached the destination
            if (x == n - 1 && y == n - 1) {
                return ans;
            }

            // Explore neighbours
            for (auto& dir : direction) {

                int newx = x + dir[0];
                int newy = y + dir[1];

                if (newx >= 0 && newx < n &&
                    newy >= 0 && newy < n &&
                    !visited[newx][newy]) {

                    visited[newx][newy] = true;

                    s.insert({
                        grid[newx][newy],
                        {newx, newy}
                    });
                }
            }
        }

        return ans;
    }
};