class Solution {
    int helper(int i, int j, int &m, int &n, vector<vector<int>>& dungeon, vector<vector<int>> &dp){
        if(i>=m || j>=n) return INT_MAX;

        if(i==m-1 && j==n-1){
            if(dungeon[m-1][n-1] <= 0) return abs(dungeon[m-1][n-1]) +1;
            else return 1;
        }

        if(dp[i][j] != -1001) return dp[i][j];

        int down=helper(i+1, j, m, n, dungeon, dp);
        int right=helper(i, j+1, m, n, dungeon, dp);
        int minHealth=min(down, right) - dungeon[i][j];

        return dp[i][j]=minHealth<=0 ? 1 : minHealth ;
    }
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m=dungeon.size();
        int n=dungeon[0].size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1001));
        return helper(0, 0, m, n, dungeon, dp);
    }
};