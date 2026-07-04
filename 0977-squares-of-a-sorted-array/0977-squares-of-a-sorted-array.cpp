class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {

        int n = nums.size();
        int j = 0;

        while (j < n && nums[j] < 0)
            j++;

        int i = j - 1;

        vector<int> res;

        while (i >= 0 && j < n) {
            int left = nums[i] * nums[i];
            int right = nums[j] * nums[j];

            if (left < right) {
                res.push_back(left);
                i--;
            } else {
                res.push_back(right);
                j++;
            }
        }

        while (i >= 0) {
            res.push_back(nums[i] * nums[i]);
            i--;
        }

        while (j < n) {
            res.push_back(nums[j] * nums[j]);
            j++;
        }

        return res;
    }
};