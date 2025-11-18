class Solution {
private:
    int helper(vector<int> nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        int n = nums.size();
        vector<int> subArr(n - 1);

        for (int i = 0; i < n - 1; ++i) {
            subArr[i] = (nums[i] + nums[i+1]) % 10;
        }

        return helper(subArr);
    }

public:
    int triangularSum(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        return helper(nums);
    }
};