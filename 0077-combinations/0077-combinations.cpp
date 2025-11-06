class Solution {
private:
    void solve(int n, int k, int start, vector<int>& curr, vector<vector<int>>& ans) {
        // Base case: when combination size == k
        if (curr.size() == k) {
            ans.push_back(curr);
            return;
        }

        // Try all numbers from 'start' to 'n'
        for (int i = start; i <= n; i++) {
            curr.push_back(i);
            solve(n, k, i + 1, curr, ans);
            curr.pop_back();  // backtrack
        }
    }

public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> curr;
        solve(n, k, 1, curr, ans);
        return ans;
    }
};
