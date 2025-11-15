class Solution {
    int helper(int i, int j, string &text1, string &text2, vector<vector<int>> &dp){
        if(i==text1.size() || j==text2.size()) return 0;

        if(text1[i]==text2[j]) {
            return 1 + helper(i+1, j+1, text1, text2, dp);
        } 

        if(dp[i][j] != -1) return dp[i][j];

        int include1=helper(i, j+1, text1, text2, dp);
        int include2=helper(i+1, j, text1, text2, dp);

        return dp[i][j]=max(include1, include2);

    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size()+1, vector<int>(text2.size()+1, -1));
        return helper(0, 0, text1, text2, dp);
    }
};