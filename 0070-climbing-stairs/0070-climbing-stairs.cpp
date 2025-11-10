class Solution {
    int helper(int n, vector<int> &dp){
        if(n==1 || n==2)
            return n;
        
        if(dp[n] != -1) return dp[n];

        return dp[n]=climbStairs(n-1) + climbStairs(n-2);
    }
public:
    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        return helper(n, dp);
    }
};