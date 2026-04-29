class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int zeroCount = 0;
        int longestWindow = 0;

        int i = 0;

        for (int j = 0; j < nums.size(); j++) {
            zeroCount += (nums[j] == 0);
            while (zeroCount > k) {
                zeroCount -= (nums[i] == 0);
                i++;
            }

            longestWindow = max(longestWindow, j - i + 1);
        }

        return longestWindow;
    }
};