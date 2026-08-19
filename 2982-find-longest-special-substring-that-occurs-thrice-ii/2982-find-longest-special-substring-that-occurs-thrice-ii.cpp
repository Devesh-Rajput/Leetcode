class Solution {
public:
    int maximumLength(string s) {
        int n = s.size();
        vector<vector<int>> freq(26, vector<int>(n + 1, 0));

        char prev = s[0];
        int len = 0;
        for (int i = 0; i < n; i++) {
            char curr = s[i];
            if (prev == curr) {
                len++;
                freq[curr - 'a'][len]++;
            } else {
                len = 1;
                freq[curr - 'a'][len]++;
                prev = curr;
            }
        }

        int res = 0;
        for (int i = 0; i < 26; i++) {
            int cumulativeSum = 0;
            for (int j = n; j > 0; j--) {
                cumulativeSum += freq[i][j];
                if (cumulativeSum > 2) {
                    res = max(res, j);
                    break;
                }
            }
        }

        return res == 0 ? -1 : res;
    }
};