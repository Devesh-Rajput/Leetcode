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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;

        ListNode* temp=head;
        ListNode* forward=temp->next;
        while(forward!=NULL){
            int val1=temp->val;
            int val2=forward->val;
            int ans=gcd(val1, val2);
            ListNode* node=new ListNode(ans);
            temp->next=node;
            node->next=forward;
            temp=forward;
            forward=forward->next;
        }
        return head;
    }
};