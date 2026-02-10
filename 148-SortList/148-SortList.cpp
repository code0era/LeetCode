// Last updated: 2/11/2026, 12:54:50 AM
#include <vector>
#include <algorithm>

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (!head) return nullptr;

        // Store values in an array (vector)
        std::vector<int> values;
        ListNode* curr = head;
        while (curr) {
            values.push_back(curr->val);
            curr = curr->next;
        }

        //  Sort the array
        std::sort(values.begin(), values.end());

        // Put values back into the linked list
        curr = head;
        for (int val : values) {
            curr->val = val;
            curr = curr->next;
        }

        return head;
    }
};