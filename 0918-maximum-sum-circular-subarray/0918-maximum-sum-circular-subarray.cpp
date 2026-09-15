class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int bestEnd1 = nums[0];
        int ans1 = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            int inc = bestEnd1 + nums[i];
            int exc = nums[i];

            bestEnd1 = max(inc, exc);
            ans1 = max(ans1, bestEnd1);
        }

        int bestEnd2 = nums[0];
        int ans2 = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            int inc = bestEnd2 + nums[i];
            int exc = nums[i];

            bestEnd2 = min(inc, exc);
            ans2 = min(ans2, bestEnd2);
        }

        int sum = accumulate(nums.begin(), nums.end(), 0);

        if (ans1 < 0)
            return ans1;

        return max(ans1, sum - ans2);
    }
};