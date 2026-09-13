class Solution {
public:
    bool helper(int i, int j, string& s) {
        while (i <= j) {
            if (s[i] != s[j])
                return 0;
            i++;
            j--;
        }
        return 1;
    }
    bool validPalindrome(string s) {
        int i = 0, j = s.size() - 1;
        int cnt = 0;

        while (i <= j) {
            if (s[i] != s[j]) {
                return helper(i + 1, j, s) || helper(i, j - 1, s);
            }
            i++;
            j--;
        }
        return 1;
    }
};