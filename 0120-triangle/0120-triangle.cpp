class Solution {
    int helper(int i, int j, int &m, int &n, vector<vector<int>>& triangle, vector<vector<int>> &dp){
        if(i==m) return 0;

        if(dp[i][j] != INT_MIN) return dp[i][j];

        int down=triangle[i][j] + helper(i+1, j, m, n, triangle, dp);
        int downRight=triangle[i][j] + helper(i+1, j+1, m, n, triangle, dp);

        return dp[i][j] = min(down, downRight);
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m=triangle.size();
        int n=triangle[m-1].size();
        vector<vector<int>> dp(m, vector<int>(n,INT_MIN));
        return helper(0, 0, m, n, triangle, dp);
    }
};