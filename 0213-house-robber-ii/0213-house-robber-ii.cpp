class Solution {
    int helper(int i, int n, vector<int>& nums, vector<int> &dp){
        if(i>n) return 0;

        if(dp[i]!=-1) return dp[i];

        int first=nums[i]+helper(i+2, n, nums, dp);
        int second=helper(i+1, n, nums, dp);
        return dp[i]=max(first, second);
    }
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1 ) return nums[0];
        vector<int> dp(n, -1);
        int first=helper(0, n-2, nums, dp);
        fill(dp.begin(), dp.end(), -1);
        int second=helper(1, n-1, nums, dp);
        return max(first, second);
    }
};