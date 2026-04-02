class Solution {
    ListNode *helper(ListNode *h1, ListNode *h2, int d){
        while(d && h1){
            h1 = h1->next;
            d--;
        }
        
        while(h1 != NULL && h2 != NULL){
            if(h1 == h2) return h1;
            h1 = h1->next;
            h2 = h2->next;
        }
        return NULL;
    } 

public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB) return NULL;

        int d1 = 0, d2 = 0;
        ListNode *tempA = headA;
        ListNode *tempB = headB;

        while(tempA){
            d1++;
            tempA = tempA->next;
        }

        while(tempB){
            d2++;
            tempB = tempB->next;
        }

        if(d1 > d2){
            return helper(headA, headB, d1 - d2);
        }
        else{
            return helper(headB, headA, d2 - d1);
        }
    }
};