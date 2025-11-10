class Solution {
    bool isPalindrome(string &sub){
        if(sub.length()==1) return true;
        int n=sub.length();
        for(int i=0; i<=n/2; i++){
            if(sub[i]!=sub[n-i-1]) return false;
        }
        return true;
    }

    void helper(int i, vector<vector<string>> &ans, vector<string> &curr, string s){
        if(i==s.length()){
            ans.push_back(curr);
            return;
        }

        for(int j=1; i+j<=s.length(); j++){
            string sub=s.substr(i,j);
            if(isPalindrome(sub)){
                curr.push_back(sub);
                helper(i+j, ans, curr, s);
                curr.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> curr;
        helper(0, ans, curr, s);
        return ans;
    }
};