class Solution {
    bool helper(int p1, int p2, vector<int>& nums, int l, int r, bool player) {
        if (l > r)
            return p1 >= p2;

        if (player) {
            return helper(p1 + nums[l], p2, nums, l + 1, r, false) ||
                   helper(p1 + nums[r], p2, nums, l, r - 1, false);
        } else {
            return helper(p1, p2 + nums[l], nums, l + 1, r, true) &&
                   helper(p1, p2 + nums[r], nums, l, r - 1, true);
        }
    }

public:
    bool predictTheWinner(vector<int>& nums) {
        bool player = 1;
        int n = nums.size();
        return helper(0, 0, nums, 0, n - 1, player);
    }
};