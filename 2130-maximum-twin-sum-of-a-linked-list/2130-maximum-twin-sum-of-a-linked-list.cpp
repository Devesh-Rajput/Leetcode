/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int pairSum(ListNode* head) {
        vector<int> nums;
        ListNode* curr=head;
        while(curr){
            nums.push_back(curr->val);
            curr=curr->next;
        }
        int i=0;
        int j=nums.size()-1;
        int ans=INT_MIN;
        while(i<j){
            ans=max(ans, nums[i]+nums[j]);
            i++;
            j--;
        }
        return ans;
    }
};