class Solution {
    void helper(int index, string &curr, int n, vector<string> &ans){
        if(index==n){
            ans.push_back(curr);
            return;
        }
        if(curr.empty() || curr.back()!='0'){
            curr+="0";
            helper(index+1, curr, n, ans);
            curr.pop_back();
        }
        
        curr+="1";
        helper(index+1, curr, n, ans);
        curr.pop_back();
        
       
    }
public:
    vector<string> validStrings(int n) {
        vector<string> ans;
        string curr="";
        helper(0, curr, n, ans);
        return ans;
    }
};