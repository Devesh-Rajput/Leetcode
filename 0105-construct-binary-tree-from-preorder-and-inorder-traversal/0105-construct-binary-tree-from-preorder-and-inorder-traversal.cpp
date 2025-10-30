/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
    int findPosition(vector<int> &inorder, int element, int n) {
        for (int i = 0; i < n; i++) {
            if (inorder[i] == element)
                return i;
        }
        return -1;
    }

    TreeNode* solve(vector<int> &inorder, vector<int> &preorder, int &index, int inorderStart, int inorderEnd, int n) {
        if (index >= n || inorderStart > inorderEnd)
            return nullptr;

        int element = preorder[index++];
        TreeNode* root = new TreeNode(element);
        int position = findPosition(inorder, element, n);

        // Build left subtree first (since preorder is Root -> Left -> Right)
        root->left = solve(inorder, preorder, index, inorderStart, position - 1, n);
        root->right = solve(inorder, preorder, index, position + 1, inorderEnd, n);

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        int preIndex = 0;
        return solve(inorder, preorder, preIndex, 0, n - 1, n);
    }
};
