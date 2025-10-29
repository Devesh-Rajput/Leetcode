/*
class Node {
  public:
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
    void solve(Node* root, vector<int>& path, int &count, int k){
        if(root==NULL)
            return;

        path.push_back(root->data);

        solve(root->left, path, count, k);
        solve(root->right, path, count, k);

        int size=path.size();
        long long sum=0;
        for(int i=size-1; i>=0; i--){
            sum+=path[i];
            if(sum==k){
                count++;
            }
        }
        path.pop_back();
    }
  public:
    int countAllPaths(Node *root, int k) {
        // code here
        vector<int> path;
        int count=0;
        solve(root, path, count, k);
        return count;
    }
};