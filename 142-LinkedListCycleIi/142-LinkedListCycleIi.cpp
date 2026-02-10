// Last updated: 2/11/2026, 12:54:53 AM
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (!head || !head->next) return nullptr;

        ListNode *slow = head;
        ListNode *fast = head;

        // Phase 1: Find if a collision occurs
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                // Phase 2: Find the start of the loop
                fast = head; 
                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow; 
            }
        }

        return nullptr; 
    }
};