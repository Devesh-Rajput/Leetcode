class Solution {
    int helper(int i, int j, int m, int n, vector<vector<int>>& matrix,
               vector<vector<int>>& dp) {
        if (j < 0 || j >= n)
            return INT_MAX;

        if (i == m - 1)
            return matrix[i][j];

        if (dp[i][j] != -101)
            return dp[i][j];

        int down = helper(i + 1, j, m, n, matrix, dp);
        int downRight =  helper(i + 1, j + 1, m, n, matrix, dp);
        int downLeft = helper(i + 1, j - 1, m, n, matrix, dp);

        return dp[i][j] = matrix[i][j] + min({down,downRight, downLeft});
    }

public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, -101));
        int minRow = INT_MAX;
        for (int k = 0; k < n; k++) {
            minRow = min(minRow, helper(0, k, m, n, matrix, dp));
        }
        return minRow;
    }
};