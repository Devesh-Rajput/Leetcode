class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        for(int i=0; i<nums.size(); i++){
            int maxE=INT_MIN;
            int minE=INT_MAX;
            for(int j=0; j<=i; j++){
                maxE=max(maxE,nums[j]);
            }

            for(int x=i; x<nums.size(); x++){
                minE=min(minE,nums[x]);
            }

            if(maxE-minE<=k) return i;
        }
        return -1;
    }
};