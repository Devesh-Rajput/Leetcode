class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<int>> adj(n + 1, vector<int>(n + 1, INT_MAX));

        for (auto& t : times) {
            int u = t[0], v = t[1], w = t[2];
            adj[u][v] = w;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        vector<int> time(n + 1, INT_MAX);
        time[k] = 0;
        pq.push({0, k});
        while (!pq.empty()) {
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for (int j = 1; j <= n; j++) {
                if (adj[node][j] != INT_MAX) {
                    if (d + adj[node][j] < time[j]) {
                        time[j] = d + adj[node][j];
                        pq.push({time[j], j});
                    }
                }
            }

        }

        int ans = INT_MIN;
        for (int i = 1; i <= n; i++) {
            if (time[i] == INT_MAX)
                return -1;
            ans = max(ans, time[i]);
        }

        return ans;
    }
};