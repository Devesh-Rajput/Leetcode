class Solution {
    void helper(int index, string &s, string &curr, vector<string> &ans){
        if(index==s.length()){
            ans.push_back(curr);
            return;
        }
        curr+=s[index];
        helper(index+1, s, curr, ans);
        curr.pop_back();
        helper(index+1, s, curr, ans);
    }
  public:
    vector<string> AllPossibleStrings(string s) {
        // Code here
        vector<string> ans;
        string curr="";
        
        helper(0, s, curr, ans);
        sort(ans.begin(), ans.end());
        return ans;
        
    }
};