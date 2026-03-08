/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
    vector<TreeNode*> helper(int n, unordered_map<int, vector<TreeNode*>> &dp) {
        if (n % 2 == 0)
            return {};
        if (n == 1) {
            TreeNode* temp = new TreeNode(0);
            return {temp};
        }
        if(dp.find(n)!=dp.end()) return dp[n];

        vector<TreeNode*> result;
        for (int i = 1; i < n; i += 2) {
            vector<TreeNode*> l = helper(i, dp);
            vector<TreeNode*> r = helper(n - i - 1, dp);

            for (auto lt : l) {
                for (auto rt : r) {
                    TreeNode* temp = new TreeNode(0);
                    temp->left = lt;
                    temp->right = rt;
                    result.push_back(temp);
                }
            }
        }
        return dp[n]=result;
    }

public:
    vector<TreeNode*> allPossibleFBT(int n) {
        unordered_map<int, vector<TreeNode*>> dp;
        return helper(n, dp);
    }
};