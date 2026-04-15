class Solution {
public:
    void dfs(int u, vector<vector<int>>& adj, vector<int>& vis, long long& cnt) {
        vis[u] = 1;
        cnt++;
        for (int v : adj[u]) {
            if (!vis[v]) {
                dfs(v, adj, vis, cnt);
            }
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<int> vis(n, 0);
        long long ans = 0;
        long long rem = n;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                long long cnt = 0;
                dfs(i, adj, vis, cnt);
                rem -= cnt;
                ans += cnt * rem;
            }
        }
    return ans;
    }
};