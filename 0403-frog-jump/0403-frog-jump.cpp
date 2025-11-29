class Solution {
    bool helper(int i, int prev, vector<int>& stones, int n, vector<vector<int>> &dp, unordered_map<int, int> &mp){
        if(i==n-1) return true;

        if(dp[i][prev]!=-1) return dp[i][prev];

        bool flag=false;
        for(int nxt=prev-1; nxt<=prev+1; nxt++){
            if(nxt>0){
                int nxt_stone=stones[i]+nxt;
                if(mp.find(nxt_stone)!=mp.end()){
                    flag=flag || helper(mp[nxt_stone], nxt, stones, n, dp, mp);
                }
            }
        }

        return dp[i][prev]=flag;
    }
public:
    bool canCross(vector<int>& stones) {
        if(stones[1]!=1) return 0;

        int n=stones.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        unordered_map<int, int> mp;
        for(int i=0; i<n; i++){
            mp[stones[i]]=i;
        }
        return helper(0, 0, stones, n, dp, mp);
    }
};