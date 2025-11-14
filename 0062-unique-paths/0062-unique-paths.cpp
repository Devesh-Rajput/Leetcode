class Solution {
    // int helper(int i, int j, int m, int n, vector<vector<int>> &dp){
       
    //     if(i==m-1 && j==n-1) return 1;

    //     if(i>=m || j>=n) return 0;

    //     if(dp[i][j] != -1) return dp[i][j];

    //     return dp[i][j]=helper(i+1, j, m, n, dp) + helper(i, j+1, m, n, dp);
    // }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1));

        for(int i=m-1; i>=0; i--){
            for(int j=n-1; j>=0; j--){
                if(i==m-1 && j==n-1) dp[i][j]=1;

                else {
                    int down = (i + 1 < m) ? dp[i + 1][j] : 0;
                    int right = (j + 1 < n) ? dp[i][j + 1] : 0;

                    dp[i][j] = down + right;
                    }
            }
        }

        return dp[0][0];
    }
};