/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<int> rightView(Node *root) {
        //  code here
        vector<int> ans;
        if(root==NULL) return ans;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            ans.push_back(q.front()->data);
            while(n--){
                Node* node=q.front();
                q.pop();
                
                if(node->right) q.push(node->right);
                if(node->left) q.push(node->left);
            }
        }
        return ans;
    
    }
};