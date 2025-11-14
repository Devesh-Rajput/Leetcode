class Solution {
    // int helper(int i, int j, int& m, int& n, vector<vector<int>>& obstacleGrid, vector<vector<int>> &dp){
    //     if(i==m-1 && j==n-1) return 1;

    //     if(i>=m || j>=n) return 0;

    //     if(dp[i][j] != -1) return dp[i][j];

    //     if(obstacleGrid[i][j]!=0) return 0;

    //     return dp[i][j]= helper(i+1, j, m, n, obstacleGrid, dp) + helper(i, j+1, m, n, obstacleGrid, dp);

    // }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        if(obstacleGrid[m-1][n-1]==1) return 0;
        vector<vector<long long>> dp(m+1, vector<long long>(n+1, 0));
        for(int i=m-1; i>=0; i--){
            for(int j=n-1; j>=0; j--){
                if(obstacleGrid[i][j]!=0) continue;
                if(i==m-1 && j==n-1) dp[i][j]=1;
                else{
                    dp[i][j] = dp[i + 1][j] + dp[i][j + 1];
                }
            }
        }

        return dp[0][0];
    }
};