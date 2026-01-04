class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int consecutive = 0;
        int ans = 0;

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 1) {
                consecutive++;
                ans = max(ans, consecutive);
            } else {
                consecutive = 0;
            }
        }
        return ans;
    }
};
