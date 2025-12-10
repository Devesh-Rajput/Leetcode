// User function Template for C++

class Solution {
  public:
    vector<int> largestValues(Node* root) {
        // code here
        vector<int> ans;
        if(root==NULL) return ans;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int len=q.size();
            int maxi=INT_MIN;
            while(len--){
                Node* node=q.front();
                q.pop();
                maxi=max(maxi, node->data);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            ans.push_back(maxi);
        }
        return ans;
    }
};