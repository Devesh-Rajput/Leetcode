class Solution {
    // int helper(int i, int j, int m, int n, vector<vector<int>>& matrix,
    //            vector<vector<int>>& dp) {
    //     if (j < 0 || j >= n)
    //         return INT_MAX;

    //     if (i == m - 1)
    //         return matrix[i][j];

    //     if (dp[i][j] != -101)
    //         return dp[i][j];

    //     int down = helper(i + 1, j, m, n, matrix, dp);
    //     int downRight =  helper(i + 1, j + 1, m, n, matrix, dp);
    //     int downLeft = helper(i + 1, j - 1, m, n, matrix, dp);

    //     return dp[i][j] = matrix[i][j] + min({down,downRight, downLeft});
    // }

public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m=matrix.size();
        vector<vector<int>> dp= matrix;
        for(int i=m-2; i>=0; i--){
            for(int j=0; j<matrix[i].size(); j++){
                int a = dp[i+1][j];
                int b = (j+1 < m) ? dp[i+1][j+1] : INT_MAX;
                int c = (j-1 >= 0) ? dp[i+1][j-1] : INT_MAX;
                dp[i][j] = matrix[i][j] + min({a, b, c});

            }
        }   
        int ans=INT_MAX;
        for(int i=0; i<matrix[0].size(); i++){
            ans=min(ans, dp[0][i]);
        } 
        return ans;
    }
};