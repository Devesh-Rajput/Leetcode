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
    ListNode* reverseLL(ListNode* node) {
        if (node == NULL || node->next == NULL)
            return node;
        ListNode* last = reverseLL(node->next);
        node->next->next = node;
        node->next = NULL;
        return last;
    }

public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next)
            return 1;
        // if (!head->next->next)
        //     return 0;

        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* revHalf = reverseLL(slow);
        ListNode* curr = head;
        while (revHalf) {
            if (curr->val != revHalf->val)
                return 0;
            curr = curr->next;
            revHalf = revHalf->next;
        }
        return 1;
    }
};