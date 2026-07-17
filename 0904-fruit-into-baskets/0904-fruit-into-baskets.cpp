class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int l = 0, ans = INT_MIN;
        unordered_map<int, int> freq;
        for (int h = 0; h < n; h++) {
            freq[fruits[h]]++;
            while (freq.size() > 2) {
                freq[fruits[l]]--;
                if (freq[fruits[l]] == 0) {
                    freq.erase(fruits[l]);
                }
                l++;
            }
            ans = max(ans, h - l + 1);
        }
        return ans;
    }
};