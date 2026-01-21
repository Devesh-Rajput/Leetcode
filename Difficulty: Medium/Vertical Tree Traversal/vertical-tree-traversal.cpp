class Solution {
    void find(Node* root, int pos, int& l, int& r) {
        if (root == NULL) return;
        l = min(l, pos);
        r = max(r, pos);
        find(root->left, pos - 1, l, r);
        find(root->right, pos + 1, l, r);
    }

public:
    vector<vector<int>> verticalOrder(Node *root) {

        int l = 0, r = 0;
        find(root, 0, l, r);

        vector<vector<int>> positive(r + 1);
        vector<vector<int>> negative(abs(l) + 1);

        queue<Node*> q;
        queue<int> index;

        q.push(root);
        index.push(0);

        while (!q.empty()) {

            int sz = q.size();
            map<int, vector<int>> level;  // col -> values at this level

            while (sz--) {
                Node* node = q.front();
                q.pop();
                int pos = index.front();
                index.pop();

                level[pos].push_back(node->data);

                if (node->left) {
                    q.push(node->left);
                    index.push(pos - 1);
                }
                if (node->right) {
                    q.push(node->right);
                    index.push(pos + 1);
                }
            }

            // ✅ push in column order, but keep left-to-right order inside vector
            for (auto &it : level) {
                int pos = it.first;
                auto &vals = it.second;

                if (pos >= 0) {
                    for (int x : vals) positive[pos].push_back(x);
                } else {
                    for (int x : vals) negative[abs(pos)].push_back(x);
                }
            }
        }

        vector<vector<int>> ans;

        for (int i = (int)negative.size() - 1; i > 0; i--) {
            ans.push_back(negative[i]);
        }
        for (int i = 0; i < (int)positive.size(); i++) {
            ans.push_back(positive[i]);
        }

        return ans;
    }
};
