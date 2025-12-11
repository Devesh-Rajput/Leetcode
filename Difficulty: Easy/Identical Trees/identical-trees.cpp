/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};
*/
class Solution {
  public:
    bool isIdentical(Node* p, Node* q) {
        // code here
        if(p==NULL && q==NULL) return 1;

        if((p==NULL && q!=NULL) || (p!=NULL && q==NULL)) return 0;

        if(p->data != q->data) return 0;

        return isIdentical(p->left, q->left) && isIdentical(p->right, q->right);
    }
};