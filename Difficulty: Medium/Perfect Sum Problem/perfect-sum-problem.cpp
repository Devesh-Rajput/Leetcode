class Solution {
    int helper(int i, int &n, int target, vector<int>& arr, vector<vector<int>> &dp){

        if(i==n ) return target==0;

        if(dp[i][target]!= -1) return dp[i][target];
        
        int include=0;
        if(arr[i]<=target) include=helper(i+1, n, target-arr[i], arr, dp);
        int exclude=helper(i+1, n, target, arr, dp);

        dp[i][target]=include+exclude ;

        return dp[i][target];

    }
  public:
    int perfectSum(vector<int>& arr, int target) {
        // code here
        int n=arr.size();
        vector<vector<int>> dp(n+1, vector<int>(target+1, -1));
        return helper(0, n, target, arr, dp);
        
    }
};