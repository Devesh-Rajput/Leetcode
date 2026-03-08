class Solution {
    int helper(int i, int& n, vector<int>& arr, int& k, vector<int>& dp) {
        if (i >= n)
            return 0;

        if (dp[i] != 0)
            return dp[i];

        int curr_max = INT_MIN;
        int result = 0;
        for (int j = i; j < n && j - i + 1 <= k; j++) {
            curr_max = max(curr_max, arr[j]);
            result = max(result, (j - i + 1) * curr_max + helper(j + 1, n, arr, k, dp));
        }
        return dp[i] = result;
    }

public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(501, 0);
        return helper(0, n, arr, k, dp);
    }
};