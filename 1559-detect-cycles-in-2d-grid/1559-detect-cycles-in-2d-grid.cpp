class Solution {
    bool dfs(int i, int j, vector<vector<char>>& grid, vector<vector<int>>& vis,
             vector<pair<int, int>>& directions, int pi, int pj) {
        int m = grid.size();
        int n = grid[0].size();
        char ch = grid[i][j];
        vis[i][j] = 1;
        for (auto& d : directions) {
            int ni = i + d.first;
            int nj = j + d.second;
            if (ni >= 0 && ni < m && nj >= 0 && nj < n && grid[ni][nj] == ch) {
                if (!vis[ni][nj]) {
                    if (dfs(ni, nj, grid, vis, directions, i, j))
                        return true;
                } else if (ni != pi && nj != pj) {
                    return true;
                }
            }
        }
        return false;
    }

public:
    bool containsCycle(vector<vector<char>>& grid) {
        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!vis[i][j]) {
                    if (dfs(i, j, grid, vis, directions, -1, -1))
                        return true;
                }
            }
        }
        return false;
    }
};