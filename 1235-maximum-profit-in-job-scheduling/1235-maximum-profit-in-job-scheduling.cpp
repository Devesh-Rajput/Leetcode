class Solution {
    int helper(int i, vector<vector<int>>& jobs, int& n,
               vector<int>& dp) {
        if (i >= n)
            return 0;

        if (dp[i] != -1)
            return dp[i];

        int next = getNextIndex(jobs, i + 1, jobs[i][1]);

        int take = jobs[i][2] + helper(next, jobs, n, dp);
        int skip = helper(i + 1, jobs, n, dp);

        return dp[i] = max(take, skip);
    }

    int getNextIndex(vector<vector<int>>& jobs, int l, int endTime) {
        int r = jobs.size() - 1;
        int ans = jobs.size();

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (jobs[mid][0] >= endTime) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }

public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();

        vector<vector<int>> jobs(n, vector<int>(3));
        for (int i = 0; i < n; i++) {
            jobs[i] = {startTime[i], endTime[i], profit[i]};
        }
        sort(jobs.begin(), jobs.end());
        vector<int> dp(n, -1);

        return helper(0, jobs, n, dp);
    }
};