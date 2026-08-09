class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int bestEnd = nums[0];
        int ans1 = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            int inc = bestEnd + nums[i];
            int exc = nums[i];

            bestEnd = max(inc, exc);
            ans1 = max(ans1, bestEnd);
        }

        int bestEnd1 = nums[0];
        int ans2 = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            int inc = bestEnd1 + nums[i];
            int exc = nums[i];

            bestEnd1 = min(inc, exc);
            ans2 = min(ans2, bestEnd1);
        }

        return max(abs(ans1), abs(ans2));
    }
};