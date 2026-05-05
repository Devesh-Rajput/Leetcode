class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {

        if(head == NULL || head->next == NULL) return head;

        int len = 1;
        ListNode* temp = head;

        while(temp->next != NULL){
            temp = temp->next;
            len++;
        }

        k = k % len;
        if(k == 0) return head;

        temp->next = head; 

        int mark = len - k;
        temp = head;

        for(int i = 1; i < mark; i++){
            temp = temp->next;
        }

        ListNode* newHead = temp->next;
        temp->next = NULL;

        return newHead;
    }
};