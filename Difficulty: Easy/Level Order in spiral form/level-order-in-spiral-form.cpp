/*
class Node
{
    int data;
    Node* left;
    Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */
class Solution {
  public:
    vector<int> findSpiral(Node* root) {
        vector<int> ans;
        if (root == nullptr) return ans;

        stack<Node*> s1;
        stack<Node*> s2;
        s1.push(root);

        while (!s1.empty() || !s2.empty()) {
            if (!s1.empty()) {
                while (!s1.empty()) {
                    Node* node = s1.top();
                    s1.pop();
                    ans.push_back(node->data);
                    if (node->right) s2.push(node->right);
                    
                    if (node->left)  s2.push(node->left); 
                }
            }

            if (!s2.empty()) {
                while (!s2.empty()) {
                    Node* node = s2.top();
                    s2.pop();
                    ans.push_back(node->data);
                    if (node->left)  s1.push(node->left);
                    
                    if (node->right) s1.push(node->right);
                }
            }
        }
        return ans;
    }
};
