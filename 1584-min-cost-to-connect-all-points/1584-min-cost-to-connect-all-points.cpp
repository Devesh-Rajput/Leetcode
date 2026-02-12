class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<pair<int, int>>> adj(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    int dist = abs(points[i][0] - points[j][0]) +
                               abs(points[i][1] - points[j][1]);
                    adj[i].push_back({j, dist});
                    adj[j].push_back({i, dist});
                }
            }
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        pq.push({0, 0});
        vector<int> vis(n, 0);
        int ans = 0;

        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();

            int node = it.second;
            int wt = it.first;
            if (vis[node] == 1)
                continue;
            ans += wt;
            vis[node] = 1;

            for (auto neigh : adj[node]) {
                int adjNode = neigh.first;
                int edgeWt = neigh.second;

                if (!vis[adjNode]) {
                    pq.push({edgeWt, adjNode});
                }
            }
        }
        return ans;
    }
};