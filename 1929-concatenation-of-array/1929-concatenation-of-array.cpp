class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> ans(nums.size() * 2);
        int i = 0;
        for (int x : nums) {
            ans[i] = x;
            i++;
        }
        int j = nums.size();
        for (int x : nums) {
            ans[j] = x;
            j++;
        }

        return ans;
    }
};
