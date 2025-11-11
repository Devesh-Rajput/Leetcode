class Solution {
    void helper(int index, string &s, unordered_set<string> &dict,
                vector<string> &curr, vector<string> &ans) {
        if (index == s.size()) {
            string temp = "";
            for (auto &word : curr) temp += word + " ";
            temp.pop_back(); 
            ans.push_back(temp);
            return;
        }

        string sub = "";
        for (int i = index; i < s.size(); i++) {
            sub += s[i];
            if (dict.count(sub)) {
                curr.push_back(sub);
                helper(i + 1, s, dict, curr, ans);
                curr.pop_back();
            }
        }
    }

public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        vector<string> curr, ans;
        helper(0, s, dict, curr, ans);
        return ans;
    }
};
