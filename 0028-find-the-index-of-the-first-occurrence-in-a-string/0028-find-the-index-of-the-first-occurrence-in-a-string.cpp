class Solution {
public:
    int strStr(string haystack, string needle) {

        int i = 0, j = 0;
        int n = haystack.size();
        int m = needle.size();

        if(m == 0) return 0;

        while(i + j < n) {

            if(haystack[i + j] == needle[j]) {
                j++;
                if(j == m) return i;
            }
            else {
                i++;
                j = 0;
            }
        }

        return -1;
    }
};