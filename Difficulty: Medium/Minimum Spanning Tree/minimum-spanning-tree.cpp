class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<pair<int,int>>> adj(V);
        for(auto ele: edges){
            int u=ele[0];
            int v=ele[1];
            int w=ele[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> vis(V, 0);
        pq.push({0, 0});

        int ans=0;
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            
            int wt=it.first;
            int node=it.second;
            
            if(vis[node]==1) continue;
            
            vis[node]=1;
            ans+=wt;
            
            for(auto neigh: adj[node]){
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