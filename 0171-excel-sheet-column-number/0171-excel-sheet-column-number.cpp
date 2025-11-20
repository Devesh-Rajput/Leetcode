							// \U0001f609\U0001f609\U0001f609\U0001f609Please upvote if it helps \U0001f609\U0001f609\U0001f609\U0001f609
class Solution {
public:
    int titleToNumber(string columnTitle) {
        int result = 0;
        for(char ch : columnTitle){
            int num = ch - 'A' + 1;
            result = result * 26 + num;
        }
        return result;
    }
};