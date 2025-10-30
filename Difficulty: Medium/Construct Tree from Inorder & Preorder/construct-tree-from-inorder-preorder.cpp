/*
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
    int findPosition(vector<int> inorder, int element, int n){
        for(int i=0; i<n; i++){
            if(element==inorder[i]){
                return i;
            }
        }
        return -1;
    }
    
    Node* solve(vector<int> inorder, vector<int> preorder, int &index, int inorderStart, int inorderEnd, int n){
        if(index>=n || inorderStart>inorderEnd)
            return NULL;
            
        int element=preorder[index++];
        Node* root=new Node(element);
        int position=findPosition(inorder, element, n);
        
        root->left = solve(inorder, preorder, index, inorderStart, position-1, n);
        root->right = solve(inorder, preorder, index, position + 1, inorderEnd, n);
        
        return root;
    }
  public:
    Node *buildTree(vector<int> &inorder, vector<int> &preorder) {
        // code here
        int n=preorder.size();
        int preorderIndex=0;
        Node* ans=solve(inorder, preorder, preorderIndex, 0, n-1, n);
        return ans;
    }
};