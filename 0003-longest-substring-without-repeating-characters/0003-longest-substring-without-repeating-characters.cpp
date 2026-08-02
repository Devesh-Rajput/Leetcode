class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0, ans = 0;
        int n = s.size();

        vector<int> freq(128, 0);

        for (int j = 0; j < n; j++) {
            freq[s[j]]++;

            while (freq[s[j]] > 1) {
                freq[s[i]]--;
                i++;
            }

            ans = max(ans, j - i + 1);
        }

        return ans;
    }
};