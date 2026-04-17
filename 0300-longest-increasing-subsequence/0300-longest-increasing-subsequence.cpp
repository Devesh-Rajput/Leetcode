class Solution {
    int helper(int i, int p, vector<int>& nums, int& n,
               vector<vector<int>>& dp) {
        if (i >= n)
            return 0;

        if (dp[i][p+1] != -1)
            return dp[i][p+1];

        int take=0;
        if (p == -1 || nums[i] > nums[p]) {
            take = 1 + helper(i + 1, i, nums, n, dp);
        }
        int skip = helper(i + 1, p, nums, n, dp);
        return dp[i][p+1] = max(take, skip);
    }

public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return helper(0, -1, nums, n, dp);
    }
};