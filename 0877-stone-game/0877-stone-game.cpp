class Solution {
    int helper(bool turn, int l, int r, vector<int>& piles,
               vector<vector<int>>& dp) {

        if (l > r)
            return 0;

        if (dp[l][r] != -1)
            return dp[l][r];

        if (turn) {
            dp[l][r] = max(piles[l] + helper(!turn, l + 1, r, piles, dp),
                           piles[r] + helper(!turn, l, r - 1, piles, dp));
        } else {
            dp[l][r] = min(-piles[l] + helper(!turn, l + 1, r, piles, dp),
                           -piles[r] + helper(!turn, l, r - 1, piles, dp));
        }

        return dp[l][r];
    }

public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));

        return helper(true, 0, n - 1, piles, dp) > 0;
    }
};