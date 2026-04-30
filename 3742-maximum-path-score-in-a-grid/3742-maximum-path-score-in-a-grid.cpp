class Solution {
public:
    int solve(vector<vector<int>>& grid, int k, int i, int j, int cost,
              vector<vector<vector<int>>>& dp, int& m, int& n) {
        if (i >= m || j >= n)
            return INT_MIN;

        int newCost = cost + (grid[i][j] > 0);

        if (newCost > k)
            return INT_MIN;

        if (i == m - 1 && j == n - 1)
            return grid[i][j];

        if (dp[i][j][cost] != -1) {
            return dp[i][j][cost];
        }

        int down = solve(grid, k, i + 1, j, newCost, dp, m, n);
        int right = solve(grid, k, i, j + 1, newCost, dp, m, n);

        int bestNext = max(down, right);

        if (bestNext == INT_MIN) {
            return dp[i][j][cost] = INT_MIN;
        }

        return dp[i][j][cost] = grid[i][j] + bestNext;
    }

    int maxPathScore(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<vector<int>>> dp(
            m + 1, vector<vector<int>>(n + 1, vector<int>(k + 1, -1)));

        int result = solve(grid, k, 0, 0, 0, dp, m, n);

        return result == INT_MIN ? -1 : result;
    }
};
