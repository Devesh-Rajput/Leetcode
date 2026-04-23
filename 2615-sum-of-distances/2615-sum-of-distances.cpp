class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n=nums.size();
        vector<long long> ans(n, 0);
        unordered_map<int ,long long> indexSum;
        unordered_map<int ,long long> count;

        for(int i=0; i<n; i++){
            long long freq=count[nums[i]];
            long long sum=indexSum[nums[i]];
            ans[i]=(i*freq)-(sum);
            count[nums[i]]++;
            indexSum[nums[i]]+=i;
        }

        count.clear();
        indexSum.clear();
        for(int i=n-1; i>=0; i--){
            long long freq=count[nums[i]];
            long long sum=indexSum[nums[i]];
            ans[i]+=(sum)-(i*freq);
            count[nums[i]]++;
            indexSum[nums[i]]+=i;
        }
        
        return ans;
    }
};