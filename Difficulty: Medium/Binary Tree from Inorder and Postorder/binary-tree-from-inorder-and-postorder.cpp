/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = nullptr;
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
    
    Node* solve(vector<int> inorder, vector<int> postorder, int &index, int inorderStart, int inorderEnd, int n){
        if(index>=n || inorderStart>inorderEnd)
            return NULL;
            
        int element=postorder[index--];
        Node* root=new Node(element);
        int position=findPosition(inorder, element, n);
        
        root->right = solve(inorder, postorder, index, position + 1, inorderEnd, n);
        root->left = solve(inorder, postorder, index, inorderStart, position-1, n);

        
        return root;
    }
  public:
    Node *buildTree(vector<int> &inorder, vector<int> &postorder) {
        // code here
        int n=postorder.size();
        int postorderIndex=n-1;
        Node* ans=solve(inorder, postorder, postorderIndex, 0, n-1, n);
        return ans;
    }
};