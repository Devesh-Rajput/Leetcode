// User function template for C++
class Solution {
    void solve(int n, int ones, int zeros, string curr, vector<string> &ans) {
    if ((int)curr.length() == n) {
        ans.push_back(curr);
        return;
    }

    // Add '1'
    curr.push_back('1');
    solve(n, ones + 1, zeros, curr, ans);
    curr.pop_back();  // backtrack

    // Add '0' only if ones > zeros
    if (ones > zeros) {
        curr.push_back('0');
        solve(n, ones, zeros + 1, curr, ans);
        curr.pop_back();  // backtrack
    }
}

  public:
    vector<string> NBitBinary(int n) {
        // Your code goes here
        vector<string> ans;
        string curr="";
        solve(n, 0, 0, curr, ans);
        return ans;
    }
};