class Solution {
    int helper(string tiles, vector<bool> &visited, int n){
        // if(){
        //     return;
        // }
        int ans=0;
        for(int i=0; i<n; i++){
            if(visited[i]==true) continue;
            if((i>0 && tiles[i]==tiles[i-1]) && visited[i-1]==false) continue;
            visited[i]=true;
            ans+=1;
            
            ans+=helper(tiles, visited, n);
            visited[i]=false;
        }

        return ans;


    }
public:
    int numTilePossibilities(string tiles) {
        sort(tiles.begin(), tiles.end());
        int n=tiles.size();
        vector<bool> visited(n, false);
        int ans=helper(tiles, visited, n);
        return ans;
    }
};