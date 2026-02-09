class Solution {
    void topological(int node, vector<vector<pair<int, int>>> &adj,
                     vector<int> &vis, stack<int> &st) {
        vis[node] = 1;

        for (auto neigh : adj[node]) {
            int v = neigh.first;
            if (!vis[v]) {
                topological(v, adj, vis, st);
            }
        }
        st.push(node);
    }

public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {

        vector<vector<pair<int, int>>> adj(V);

        for (auto ele : edges) {
            int u = ele[0];
            int v = ele[1];
            int w = ele[2];
            adj[u].push_back({v, w});
        }

        vector<int> vis(V, 0);
        stack<int> st;

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                topological(i, adj, vis, st);
            }
        }

        vector<int> dist(V, INT_MAX);
        dist[0] = 0;

        while (!st.empty()) {
            int node = st.top();
            st.pop();

            if (dist[node] != INT_MAX) {
                for (auto neigh : adj[node]) {
                    int v = neigh.first;
                    int w = neigh.second;

                    if (dist[node] + w < dist[v]) {
                        dist[v] = dist[node] + w;
                    }
                }
            }
        }
        
        for (int i = 0; i < V; i++) {
            if (dist[i] == INT_MAX)
                dist[i] = -1;
        }


        return dist;
    }
};
