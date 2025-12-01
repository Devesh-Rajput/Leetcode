class Solution {
    int helper(int i, int d, vector<int>& jobDifficulty, vector<vector<int>>& dp){
        int n = jobDifficulty.size();
        if (n - i < d) return INT_MAX;
        if (d == 1){
            int maxi = INT_MIN;
            for (int k = i; k < n; ++k) maxi = max(maxi, jobDifficulty[k]);
            return maxi;
        }
        if (dp[i][d] != -1) return dp[i][d];

        int curMax = INT_MIN;
        int best = INT_MAX;
        for (int j = i; j <= n - d; ++j){
            curMax = max(curMax, jobDifficulty[j]);
            int sub = curMax + helper(j + 1, d - 1, jobDifficulty, dp);
            best = min(best, sub);
        }
        return dp[i][d] = best;
    }

public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        if (n < d) return -1;
        vector<vector<int>> dp(n, vector<int>(d + 1, -1));
        return helper(0, d, jobDifficulty, dp);
    }
};
