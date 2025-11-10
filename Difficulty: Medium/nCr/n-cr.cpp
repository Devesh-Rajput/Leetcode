class Solution {
    int helper(int n, int r, vector<vector<int>> &dp){
        if (r > n) return 0;
        if (r == 0 || r == n) return 1;

        if (dp[n][r] != -1)
            return dp[n][r];

        return dp[n][r] = helper(n - 1, r - 1, dp) + helper(n - 1, r, dp);
    }
  public:
    int nCr(int n, int r) {
        // code here
        vector<vector<int>> dp(n + 1, vector<int>(r + 1, -1));
        return helper(n, r, dp);
    }
};