class Solution {
public:
    bool palindrome(int i, int j, string &s, vector<vector<int>> &dp) {
        if (i >= j)
            return true;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (s[i] == s[j])
            return dp[i][j] = palindrome(i + 1, j - 1, s, dp);

        return dp[i][j] = false;
    }

    int countSubstrings(string s) {
        int n = s.size();
        int ans = 0;

        vector<vector<int>> dp(n, vector<int>(n, -1));

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (palindrome(i, j, s, dp))
                    ans++;
            }
        }

        return ans;
    }
};