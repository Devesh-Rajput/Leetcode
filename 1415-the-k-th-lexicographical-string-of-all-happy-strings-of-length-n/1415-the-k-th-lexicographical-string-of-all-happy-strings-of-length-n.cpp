class Solution {
public:
    void helper(int n, string &curr, vector<string> &ans) {
        if (curr.length() == n) {
            ans.push_back(curr);
            return;
        }
        
        for (char ch = 'a'; ch <= 'c'; ch++) {
            if (!curr.empty() && curr.back() == ch)
                continue;
            
            curr.push_back(ch);
            helper(n, curr, ans);
            curr.pop_back();
        }
    }

    string getHappyString(int n, int k) {
        string curr = "";
        vector<string> ans;
        helper(n, curr, ans);

        if (ans.size() < k) 
            return "";
        
        return ans[k - 1];
    }
};