class Solution {
public:
    int m, n;
    vector<vector<int>> dp;
    vector<vector<int>> dir = {{-1,0},{1,0},{0,-1},{0,1}};

    bool dfs(int i, int j, int health, vector<vector<int>>& grid) {

        if (health <= 0) return false;

        if (i == m - 1 && j == n - 1)
            return true;

        if (dp[i][j] >= health)
            return false;

        dp[i][j] = health;

        for (auto &d : dir) {
            int ni = i + d[0];
            int nj = j + d[1];

            if (ni >= 0 && nj >= 0 && ni < m && nj < n) {
                int newHealth = health - grid[ni][nj];
                if (dfs(ni, nj, newHealth, grid))
                    return true;
            }
        }

        return false;
    }

    bool findSafeWalk(vector<vector<int>>& grid, int health) {

        m = grid.size();
        n = grid[0].size();

        dp.assign(m, vector<int>(n, -1));

        int startHealth = health - grid[0][0];

        return dfs(0, 0, startHealth, grid);
    }
};