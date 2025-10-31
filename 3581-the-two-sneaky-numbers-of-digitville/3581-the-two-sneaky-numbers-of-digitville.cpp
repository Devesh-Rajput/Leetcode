class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> freq(n, 0); 
        vector<int> ans;

        for (int num : nums) {
            freq[num]++;
        }

        for (int i = 0; i < freq.size(); i++) {
            if (freq[i] > 1) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};
