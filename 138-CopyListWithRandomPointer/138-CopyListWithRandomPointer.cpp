// Last updated: 2/11/2026, 10:35:09 PM
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;

        // 1) Insert cloned nodes after each original node
        Node* cur = head;
        while (cur) {
            Node* copy = new Node(cur->val);
            copy->next = cur->next;
            cur->next = copy;
            cur = copy->next;
        }

        // 2) Assign random pointers for the cloned nodes
        cur = head;
        while (cur) {
            Node* copy = cur->next;
            copy->random = (cur->random) ? cur->random->next : nullptr;
            cur = copy->next;
        }

        // 3) Detach the cloned list from the original list
        Node* dummy = new Node(0);
        Node* copyCur = dummy;
        cur = head;

        while (cur) {
            Node* copy = cur->next;
            Node* nxt = copy->next;

            copyCur->next = copy;
            copyCur = copy;

            cur->next = nxt;   // restore original
            cur = nxt;
        }

        return dummy->next;
    }
};