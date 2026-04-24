class Solution {
    bool allZero(vector<int> count) {
        for (int e : count) {
            if (e != 0)
                return 0;
        }
        return 1;
    }

public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> count(26, 0);
        for (int i = 0; i < p.size(); i++) {
            count[p[i] - 'a']++;
        }
        vector<int> ans;
        int i = 0, j = 0;
        while (j < s.size()) {
            count[s[j] - 'a']--;
            if ((j - i + 1) == p.size()) {
                if (allZero(count)) {
                    ans.push_back(i);
                }
                count[s[i] - 'a']++;
                i++;
            }
            j++;
        }
        return ans;
    }
};