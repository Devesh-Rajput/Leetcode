class Solution {
    void helper(vector<int> nums, vector<int> &curr, vector<bool> &visited, vector<vector<int>> &ans){
        if(curr.size()==nums.size()){
            ans.push_back(curr);
            return; 
        }

        for(int i=0; i<nums.size(); i++){
            if(visited[i]==true) continue;
            if((i>0 && nums[i]==nums[i-1]) && visited[i-1]==false) continue;

            visited[i]=true;
            curr.push_back(nums[i]);
            helper(nums, curr, visited, ans);
            curr.pop_back();
            visited[i]=false;

        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        vector<bool> visited(nums.size(), false);
        sort(nums.begin(), nums.end());
        helper(nums, curr, visited, ans);
        return ans;
    }
};