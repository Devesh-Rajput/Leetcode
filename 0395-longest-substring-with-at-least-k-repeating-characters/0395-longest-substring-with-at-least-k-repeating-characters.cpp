class Solution {
public:
    int longestSubstring(string s, int k) {

        int n = s.size();
        int ans = 0;

        for (int low = 0; low < n; low++) {

            unordered_map<char, int> freq;

            for (int high = low; high < n; high++) {

                freq[s[high]]++;

                bool valid = true;

                for (auto it : freq) {
                    if (it.second < k) {
                        valid = false;
                        break;
                    }
                }

                if (valid) {
                    ans = max(ans, high - low + 1);
                }
            }
        }

        return ans;
    }
};