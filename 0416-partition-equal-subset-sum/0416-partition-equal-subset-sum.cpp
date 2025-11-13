class Solution {
    bool helper(int i, int &n, int target, vector<int>& nums, vector<vector<int>> &dp){
        if(target==0) return true;

        if(i>=n || target<0) return false;

        if(dp[i][target]!= -1) return dp[i][target];

        bool include=helper(i+1, n, target-nums[i], nums, dp);
        bool exclude=helper(i+1, n, target, nums, dp);

        dp[i][target]=(include || exclude) ? 1 : 0 ;

        return dp[i][target];

    }
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int total=0;
        for(int i: nums){
            total+=i;
        }
        if(total%2 != 0) return false;

        int target=total/2;
        vector<vector<int>> dp(n, vector<int>(target+1, -1));
        return helper(0, n, target, nums, dp);
    }
};