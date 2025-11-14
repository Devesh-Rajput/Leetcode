class Solution {
    // int helper(int i, int j, int &m, int &n, vector<vector<int>>& triangle, vector<vector<int>> &dp){
    //     if(i==m) return 0;

    //     if(dp[i][j] != INT_MIN) return dp[i][j];

    //     int down=triangle[i][j] + helper(i+1, j, m, n, triangle, dp);
    //     int downRight=triangle[i][j] + helper(i+1, j+1, m, n, triangle, dp);

    //     return dp[i][j] = min(down, downRight);
    // }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m=triangle.size();
        vector<vector<int>> dp= triangle;
        for(int i=m-2; i>=0; i--){
            for(int j=0; j<triangle[i].size(); j++){
                dp[i][j]=triangle[i][j]+min(dp[i+1][j], dp[i+1][j+1]);
            }
        }
        return dp[0][0];
    }
};
