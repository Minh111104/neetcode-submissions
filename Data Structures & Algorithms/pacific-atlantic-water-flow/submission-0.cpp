class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> result;

        if (heights.empty() || heights[0].empty()) {
            return result;
        }

        int m = heights.size();
        int n = heights[0].size();

        // Initialize matrices to mark cells reachable by Pacific and Atlantic Oceans
        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));

        // Define directions for BFS (up, down, left, right)
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        // Perform BFS starting from cells adjacent to Pacific Ocean (left and top edges)
        for (int i = 0; i < m; ++i) {
            bfs(heights, pacific, i, 0, directions);
        }
        for (int j = 0; j < n; ++j) {
            bfs(heights, pacific, 0, j, directions);
        }

        // Perform BFS starting from cells adjacent to Atlantic Ocean (right and bottom edges)
        for (int i = 0; i < m; ++i) {
            bfs(heights, atlantic, i, n - 1, directions);
        }
        for (int j = 0; j < n; ++j) {
            bfs(heights, atlantic, m - 1, j, directions);
        }

        // Find cells that can reach both oceans
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (pacific[i][j] && atlantic[i][j]) {
                    result.push_back({i, j});
                }
            }
        }
        return result;
    }

private:
    void bfs(vector<vector<int>>& heights, vector<vector<bool>>& ocean, int startRow, int startCol, const vector<pair<int, int>>& directions) {
        int m = heights.size();
        int n = heights[0].size();

        queue<pair<int, int>> q;
        q.push({startRow, startCol});
        ocean[startRow][startCol] = true;

        while (!q.empty()) {
            pair<int, int> current = q.front();
            q.pop();

            for (const auto& dir : directions) {
                int newRow = current.first + dir.first;
                int newCol = current.second + dir.second;

                // Check if the neighbor is within bounds and has a greater or equal height
                if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n &&
                    !ocean[newRow][newCol] && heights[newRow][newCol] >= heights[current.first][current.second]) {
                    q.push({newRow, newCol});
                    ocean[newRow][newCol] = true;
                }
            }
        }
    }
};