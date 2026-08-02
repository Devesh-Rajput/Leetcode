class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxEnd=nums[0];
        int minEnd=nums[0];
        int res=nums[0];
        for(int i=1; i<nums.size(); i++){
            int ch1=maxEnd*nums[i];
            int ch2=minEnd*nums[i];
            int ch3=nums[i];
            maxEnd=max(ch1,max(ch2,ch3));
            minEnd=min(ch1,min(ch2,ch3));
            res=max(res,max(maxEnd,minEnd));
        }
        return res;
    }
};