// Last updated: 2/11/2026, 7:57:20 PM
1class Solution {
2public:
3    ListNode* reverseKGroup(ListNode* head, int k) {
4        if(!head || k == 1) return head;
5
6        ListNode dummy(0);
7        dummy.next = head;
8
9        ListNode* prevGroup = &dummy;
10
11        while(true) {
12            // find kth node
13            ListNode* kth = prevGroup;
14            for(int i = 0; i < k && kth; i++) {
15                kth = kth->next;
16            }
17            if(!kth) break;
18
19            ListNode* groupNext = kth->next;
20
21            // reverse group
22            ListNode* prev = groupNext;
23            ListNode* curr = prevGroup->next;
24
25            while(curr != groupNext) {
26                ListNode* temp = curr->next;
27                curr->next = prev;
28                prev = curr;
29                curr = temp;
30            }
31// reconnect
32            ListNode* temp = prevGroup->next;
33            prevGroup->next = kth;
34            prevGroup = temp;
35            
36        }
37
38        return dummy.next;
39    }
40};