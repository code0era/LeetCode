// Last updated: 2/7/2026, 8:01:59 PM
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    ListNode* rev(ListNode* h) {
        ListNode *p = NULL, *c = h;
        while (c) {
            ListNode* n = c->next;
            c->next = p;
            p = c;
            c = n;
        }
        return p;
    }
public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;

        // 1) find middle
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        // if odd length, skip the middle node
        if (fast) slow = slow->next;

        // 2) reverse 2nd half
        ListNode* second = rev(slow);

        // 3) compare
        ListNode* first = head;
        ListNode* tmp = second;
        while (tmp) {
            if (first->val != tmp->val) return false;
            first = first->next;
            tmp = tmp->next;
        }


        return true;
    }
};