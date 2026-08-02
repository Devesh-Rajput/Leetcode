class Solution {
public:
    void toLowercase(string &s){
        for(char &c : s){
            if(c >= 'A' && c <= 'Z')
                c = c - 'A' + 'a';
        }
    }

    bool isPalindrome(string s) {
        toLowercase(s);

        int i = 0;
        int j = s.size() - 1;

        while(i < j){

            while(i < j && !isalnum(s[i])) i++;
            while(i < j && !isalnum(s[j])) j--;

            if(s[i] != s[j])
                return false;

            i++;
            j--;
        }

        return true;
    }
};