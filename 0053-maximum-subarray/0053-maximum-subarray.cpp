class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int bestEnd = nums[0];
        int ans = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            int inc = bestEnd + nums[i];
            int exc = nums[i];

            bestEnd = max(inc, exc);
            ans = max(ans, bestEnd);
        }
        return ans;
    }
};