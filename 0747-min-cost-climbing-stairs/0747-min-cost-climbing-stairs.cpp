class Solution {
    int helper(int n, vector<int>& cost, vector<int>& dp) {
        if (n == 0) return cost[0];
        if (n == 1) return cost[1];

        if (dp[n] != -1) return dp[n];

        int oneStepBefore = helper(n - 1, cost, dp);
        int twoStepsBefore = helper(n - 2, cost, dp);

        return dp[n] = cost[n] + min(oneStepBefore, twoStepsBefore);
    }

public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n, -1);

        int costFromLast = helper(n - 1, cost, dp);
        int costFromSecondLast = helper(n - 2, cost, dp);

        return min(costFromLast, costFromSecondLast);
    }
};
