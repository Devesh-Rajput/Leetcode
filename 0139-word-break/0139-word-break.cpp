class Solution {
    bool helper(int index, string &s, unordered_set<string> &dict, vector<int> &dp){
        if(index==s.size()) return true;

        if(dp[index] != -1) return dp[index];

        string sub="";
        for(int j=index; j < s.size(); j++){
            sub+=s[j];
            auto idx=dict.find(sub);
           
            if(idx!=dict.end()){
                if(helper(j+1, s, dict, dp)){
                   return dp[index]=true;
                }
            }
        }
        return  dp[index]=false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        vector<int> dp(s.size(), -1);
        return helper(0, s, dict, dp);
    }
};