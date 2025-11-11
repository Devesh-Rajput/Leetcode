class Solution {
    int helper(int i, int j, int& m, int& n, vector<vector<int>>& obstacleGrid, vector<vector<int>> &dp){
        if(i==m-1 && j==n-1) return 1;


        if(i>=m || j>=n) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        if(obstacleGrid[i][j]!=0) return 0;

        return dp[i][j]= helper(i+1, j, m, n, obstacleGrid, dp) + helper(i, j+1, m, n, obstacleGrid, dp);

    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();

        if(obstacleGrid[m-1][n-1]==1)return 0;

        vector<vector<int>> dp(m, vector<int>(n, -1));

        return helper(0,0,m,n,obstacleGrid,dp);
    }
};