// Last updated: 2/11/2026, 10:35:46 PM
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || k == 1) return head;

        ListNode dummy(0);
        dummy.next = head;

        ListNode* prevGroup = &dummy;

        while(true) {
            // find kth node
            ListNode* kth = prevGroup;
            for(int i = 0; i < k && kth; i++) {
                kth = kth->next;
            }
            if(!kth) break;

            ListNode* groupNext = kth->next;

            // reverse group
            ListNode* prev = groupNext;
            ListNode* curr = prevGroup->next;

            while(curr != groupNext) {
                ListNode* temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
            }
// reconnect
            ListNode* temp = prevGroup->next;
            prevGroup->next = kth;
            prevGroup = temp;
            
        }

        return dummy.next;
    }
};