class Solution {
    int helper(int i, vector<int>& nums, vector<int> &dp){
        if(i==nums.size()-1) return nums[i];

        else if(i>=nums.size()) return 0;

        if(dp[i]!=-1) return dp[i];

        int first=nums[i]+helper(i+2, nums, dp);
        int second=helper(i+1, nums, dp);
        return dp[i]=max(first, second);
    }
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1 && nums[0]==0) return 0;
        vector<int> dp(nums.size(), -1);
        return helper(0, nums, dp);
    }
};