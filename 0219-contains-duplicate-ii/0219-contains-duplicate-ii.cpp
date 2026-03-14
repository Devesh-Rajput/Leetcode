class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> freq;
        int i=0, j=0;
        while(j<nums.size()){
            if(abs(i-j)>k){
                freq.erase(nums[i]);
                i++;
            }

            if(freq.find(nums[j])!=freq.end()){
                return true;
            }

            freq.insert(nums[j++]);
        }
        return 0;
    }
};