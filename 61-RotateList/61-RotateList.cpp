// Last updated: 2/11/2026, 7:54:53 PM
1class Solution {
2public:
3    ListNode* rotateRight(ListNode* head, int k) {
4        if(!head || !head->next || k==0) return head;
5
6        // find length
7        int len = 1;
8        ListNode* last = head;
9        while(last->next) {
10            last = last->next;
11            len++;
12        }
13
14        k = k % len;
15        if(k == 0) return head;
16
17        // make circular
18        last->next = head;
19
20        // find new tail
21        int steps = len - k;
22        ListNode* tail = head;
23        for(int i = 1; i < steps; i++) {
24            tail = tail->next;
25        }
26
27        // break
28        ListNode* newHead = tail->next;
29        tail->next = NULL;
30
31        return newHead;
32    }
33};