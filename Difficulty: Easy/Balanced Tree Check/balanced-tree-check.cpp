/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
    int height(Node* root, bool &valid){
        if(root==NULL) return 0;
        
        int left=height(root->left, valid);
        int right=height(root->right, valid);
        if(abs(left-right)>1){
            valid=0;
            return 0;
        }
        return 1 + max(left, right);;
        
    }
  public:
    bool isBalanced(Node* root) {
        // code here
        bool valid=1;
        int h=height(root, valid);
        return valid;
        
    }
};