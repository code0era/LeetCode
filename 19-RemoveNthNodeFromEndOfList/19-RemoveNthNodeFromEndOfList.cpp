// Last updated: 2/11/2026, 12:55:19 AM
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* f= dummy;
        ListNode* s= dummy;
        for(int i  =0 ; i< n ; i++){
            f = f->next;
        }
        while(f->next!=nullptr){
            f = f->next;
            s = s->next;
        }
        ListNode*  toDel = s->next;
        s->next = s->next->next;
        delete(toDel);
        ListNode* nhead = dummy->next;
        delete(dummy);
        return nhead;

    }
};