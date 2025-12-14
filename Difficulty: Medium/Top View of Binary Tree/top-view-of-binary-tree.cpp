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
    void find(Node* root, int &l, int &r, int pos){
        if(root==nullptr) return;
        
        l=min(l, pos);
        r=max(r, pos);
        find(root->left, l, r, pos-1);
        find(root->right, l, r, pos+1);
    }
  public:
    vector<int> topView(Node *root) {
        // code here
        int l=0, r=0;
        find(root, l, r, 0);
        vector<int> ans(r-l+1);
        vector<bool> filled(r-l+1, 0);
        queue<Node*> q;
        queue<int> index;
        
        q.push(root);
        index.push(-l);
        
        while(!q.empty()){
            Node* node=q.front();
            q.pop();
            int i=index.front();
            index.pop();
            
            if(!filled[i]){
                filled[i]=1;
                ans[i]=node->data;
            }
            
            if(node->left){
                q.push(node->left);
                index.push(i-1);
            }
            if(node->right){
                q.push(node->right);
                index.push(i+1);
            }
        }
        return ans;
        
    }
};