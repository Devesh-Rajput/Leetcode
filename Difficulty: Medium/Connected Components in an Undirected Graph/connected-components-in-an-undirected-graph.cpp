class Solution {
    void helper(int st, vector<vector<int>> &adj, vector<int> &vis, vector<int> &component){
        vis[st]=true;
        component.push_back(st);
        
        for(auto neigh: adj[st]){
            if(!vis[neigh]){
                helper(neigh, adj, vis, component);
            }
        }
    }
  public:
    vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>> adj(V);
        for(auto ele: edges){
            int u=ele[0];
            int v=ele[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> vis(V, 0);
        vector<vector<int>> ans;
        for(int i=0; i<V; i++){
            vector<int> component;
            if(!vis[i]){
                helper(i, adj, vis, component);
                sort(component.begin(), component.end());
                ans.push_back(component);
            }
        }
        return ans;
    }
};
