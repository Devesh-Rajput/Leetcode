/*Complete the function below
Node is as follows:
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
    bool parent(Node* root, int a, int b){
        if(root == nullptr) return false;
        if(root->left && root->right){
            int l = root->left->data;
            int r = root->right->data;
            if((l == a && r == b) || (l == b && r == a)) return true;
        }
        return parent(root->left, a, b) || parent(root->right, a, b);
    }
public:
    bool isCousins(Node* root, int a, int b) {
        if(root == nullptr) return false;
        if(a == b) return false;

        queue<Node*> q;
        q.push(root);
        int l1 = -1, l2 = -1;
        int level = 0;

        while(!q.empty()){
            int n = q.size();
            for(int i = 0; i < n; ++i){
                Node* node = q.front(); q.pop();
                if(node->data == a) l1 = level;
                if(node->data == b) l2 = level;

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }

            // If one was found on this level but the other wasn't, they can't be cousins
            if((l1 != -1 && l2 == -1) || (l2 != -1 && l1 == -1)) return false;
            if(l1 != -1 && l2 != -1) break;
            ++level;
        }

        // both must be present and at same level and not siblings
        if(l1 == -1 || l2 == -1) return false;
        return (l1 == l2) && !parent(root, a, b);
    }
};
