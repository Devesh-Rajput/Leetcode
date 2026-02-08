class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                          int k) {
        vector<int> dis(n, INT_MAX);
        unordered_map<int, vector<pair<int, int>>> adj;

        for (auto a : flights) {
            int u = a[0];
            int v = a[1];
            int w = a[2];
            adj[u].push_back({v, w});
        }

        queue<pair<int, int>> q;
        q.push({src, 0});
        dis[src]=0;
        int step=0;
        while(!q.empty() && step<=k){
            int N=q.size();
            while(N--){
                int u=q.front().first;
                int d=q.front().second;
                q.pop();
                for(auto neigh: adj[u]){
                    int v=neigh.first;
                    int w=neigh.second;
                    if(dis[v]>d+w){
                        dis[v]=d+w;
                        q.push({v, d+w});
                    }
                }
            }
            step++;
        }

        if(dis[dst]==INT_MAX) return -1;
        return dis[dst];
    }
};