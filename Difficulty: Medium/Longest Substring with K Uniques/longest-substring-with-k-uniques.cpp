class Solution {
public:
    int longestKSubstr(string &s, int k) {
        int low = 0;
        int res = -1;
        unordered_map<char, int> freq;

        for (int high = 0; high < s.size(); high++) {
            freq[s[high]]++;

            while (freq.size() > k) {
                freq[s[low]]--;
                if (freq[s[low]] == 0)
                    freq.erase(s[low]);
                low++;
            }

            if (freq.size() == k) {
                res = max(res, high - low + 1);
            }
        }

        return res;
    }
};