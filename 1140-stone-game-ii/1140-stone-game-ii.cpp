class Solution {
public:
    int helper(int person, int i, int M, vector<int>& piles,
               vector<vector<vector<int>>>& dp) {

        if (i >= piles.size())
            return 0;

        if (dp[person][i][M] != -1)
            return dp[person][i][M];

        int stone = 0;
        int result = (person == 1) ? -1 : INT_MAX;

        for (int x = 1; x <= 2 * M && i + x <= piles.size(); x++) {

            stone += piles[i + x - 1];

            if (person) {
                result =
                    max(result, stone + helper(0, i + x, max(M, x), piles, dp));
            } else {
                result = min(result, helper(1, i + x, max(M, x), piles, dp));
            }
        }

        return dp[person][i][M] = result;
    }

    int stoneGameII(vector<int>& piles) {

        int n = piles.size();

        vector<vector<vector<int>>> dp(
            2, vector<vector<int>>(n + 1, vector<int>(n + 1, -1)));

        return helper(1, 0, 1, piles, dp);
    }
};