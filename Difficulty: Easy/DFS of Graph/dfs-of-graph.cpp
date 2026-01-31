class Solution {
  private:
    void dfs(int start, vector<vector<int>> & adj, int vis[], vector<int>& ans){
        vis[start]=1;
        ans.push_back(start);
        for(auto it: adj[start]){
            if(!vis[it]){
                dfs(it, adj, vis, ans);
            }
        }
    }
  public:
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        int vis[adj.size()]={0};
        int start=0;
        vis[start]=1;
        vector<int> ans;
        dfs(start, adj, vis, ans);
        return ans;
    }
};