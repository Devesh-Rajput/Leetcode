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
    
    void tView(Node* root, int pos, vector<int> &ans, vector<int> &level, int lvl){
        if(root==NULL) return;
        
        if(level[pos]>lvl){
            ans[pos]=root->data;
            level[pos]=lvl;
        }
        
        tView(root->left, pos-1, ans, level, lvl+1);
        tView(root->right, pos+1, ans, level, lvl+1);
    }
    
  public:
    vector<int> topView(Node *root) {
        // code here
        int l=0, r=0;
        find(root, l, r, 0);
        vector<int> ans(r-l+1);
        vector<int> level(r-l+1, INT_MAX);
        
        tView(root, -1*l, ans, level, 0);
        return ans;
        
    }
};