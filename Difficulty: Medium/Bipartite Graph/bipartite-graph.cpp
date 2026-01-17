class Solution {
  public:
    bool isBipartite(int V, vector<vector<int>> &edges) {
        // Code here
        vector<vector<int>> adj(V);
        for(auto &e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<int> vis(adj.size(), -1);
        queue<int> q;
        
        for(int i=0; i<V; i++){
            if(vis[i]==-1){
                q.push(i);
                vis[i]=1;
                while(!q.empty()){
                    int ele=q.front();
                                        q.pop();

                    int color=vis[ele];
                    for(auto &n:adj[ele]){
                        if(vis[n]==-1){
                            vis[n]=1-color;
                            q.push(n);
                        }
                        else{
                            if(vis[n]==color){ 
                                return false;
                            }
                        }
                    }
                }
            }
        }
        return true;
    }
};