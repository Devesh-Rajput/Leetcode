class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> minIdx(n,0);
        int minE = INT_MAX;
        for (int i = n - 1; i >= 0; i--) {
            minE = min(minE, nums[i]);
            minIdx[i] = minE;
        }

        int maxE = INT_MIN;
        for (int i = 0; i < n; i++) {
            maxE = max(maxE, nums[i]);

            if (maxE - minIdx[i] <= k)
                return i;
        }

        return -1;
    }
};