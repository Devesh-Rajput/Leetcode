class Solution {
public:
    string intToRoman(int n) {
        vector<int> val{1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        vector<string> sym{"M", "CM", "D", "CD", "C", "XC", "L",
                           "XL", "X", "IX", "V", "IV", "I"};

        string result = "";

        while (n > 0) {
            int i = 0;

            while (n < val[i]) {
                i++;
            }

            int times = n / val[i];
            int rem = n % val[i];

            while (times > 0) {
                result.append(sym[i]);
                times--;
            }

            n = rem;
        }

        return result;
    }
};