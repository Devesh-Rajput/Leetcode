class Solution {
    // int helper(int i, vector<int>& nums, vector<int> &dp){
    //     if(i==nums.size()-1) return nums[i];

    //     else if(i>=nums.size()) return 0;

    //     if(dp[i]!=-1) return dp[i];

    //     int first=nums[i]+helper(i+2, nums, dp);
    //     int second=helper(i+1, nums, dp);
    //     return dp[i]=max(first, second);
    // }
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1 ) return nums[0];

        vector<int> dp(nums.size()+1);
        dp[0]=nums[0];
        dp[1]=max(nums[0], nums[1]);
        for(int i=2; i<nums.size(); i++){
            dp[i]=max(nums[i]+dp[i-2], dp[i-1]);
        }
        return dp[nums.size()-1];
    }
};