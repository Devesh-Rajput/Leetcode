class Solution {
public:
    int helper(int num) {
        string s = to_string(num);

        sort(s.begin(), s.end());

        string encrypted(s.size(), s.back()); 
        return stoi(encrypted);
    }

    int sumOfEncryptedInt(vector<int>& nums) {
        int ans = 0;

        for (int num : nums) {
            ans += helper(num);
        }

        return ans;
    }
};