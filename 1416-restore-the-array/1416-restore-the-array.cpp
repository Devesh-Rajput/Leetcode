class Solution {
    const int MOD = 1e9 + 7;

    int helper(int st, string &s, int &k, int n, vector<long long> &dp){
        if(st >= n) return 1;

        if(s[st]=='0') return 0;

        long ans=0;
        long long num=0;

        if(dp[st]!=-1) return dp[st];

        for(int end=st; end<n; end++){
            num = (num*10) + (s[end]-'0');
            if(num>k) break;
            ans = (ans+helper(end+1, s, k, n, dp))%MOD;
        }
        return dp[st]=ans;
    }
public:
    int numberOfArrays(string s, int k) {
        int n=s.size();
        vector<long long> dp(n+1, -1);
        return helper(0, s, k, n, dp);
    }
};