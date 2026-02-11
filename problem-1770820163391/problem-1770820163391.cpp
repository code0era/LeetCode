// Last updated: 2/11/2026, 7:59:23 PM
1/*
2// Definition for a Node.
3class Node {
4public:
5    int val;
6    Node* next;
7    Node* random;
8
9    Node(int _val) {
10        val = _val;
11        next = NULL;
12        random = NULL;
13    }
14};
15*/
16
17class Solution {
18public:
19    Node* copyRandomList(Node* head) {
20        if (!head) return nullptr;
21
22        // 1) Insert cloned nodes after each original node
23        Node* cur = head;
24        while (cur) {
25            Node* copy = new Node(cur->val);
26            copy->next = cur->next;
27            cur->next = copy;
28            cur = copy->next;
29        }
30
31        // 2) Assign random pointers for the cloned nodes
32        cur = head;
33        while (cur) {
34            Node* copy = cur->next;
35            copy->random = (cur->random) ? cur->random->next : nullptr;
36            cur = copy->next;
37        }
38
39        // 3) Detach the cloned list from the original list
40        Node* dummy = new Node(0);
41        Node* copyCur = dummy;
42        cur = head;
43
44        while (cur) {
45            Node* copy = cur->next;
46            Node* nxt = copy->next;
47
48            copyCur->next = copy;
49            copyCur = copy;
50
51            cur->next = nxt;   // restore original
52            cur = nxt;
53        }
54
55        return dummy->next;
56    }
57};