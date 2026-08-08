/*
Merge K Sorted Linked Lists:
Need:
Min Heap + Linked List.

Min Heap:
Keeps the smallest CURRENT node from each list.
Allows us to get the smallest node in O(log k).

Why only one node per list?
Because every list is already sorted.
After taking a node, only its next node can become
the next candidate from that list.

Example:
L1: 1 -> 4 -> 7
L2: 2 -> 3 -> 8
L3: 0 -> 5 -> 9

Initial heap:
[1, 2, 0]

Take 0.
Add 0->next (5) to heap.

Heap:
[1, 2, 5]

Take 1.
Add 1->next (4).

Continue until heap is empty.

Use a Min Heap:
C++ priority_queue is normally a Max Heap, so use a custom comparator to make it a Min Heap.

Doubly/Single Linked List result:
Use a dummy node and a tail pointer.

dummy -> result...

tail always points to the last node.

Algorithm:
1. Put the first node of every non-empty list into heap.
2. Create dummy node and tail.
3. While heap is not empty:
   - Take smallest node.
   - Remove it from heap.
   - Attach it to the result.
   - If node->next exists, push it into heap.
4. Return dummy->next.

Main insight:
K sorted lists
-> keep one candidate from each list
-> Min Heap finds smallest candidate
-> add it to result
-> add its next node
-> repeat.

Time Complexity:
O(N log k)

N = total number of nodes
k = number of linked lists

Each node is pushed/popped from a heap
of size at most k.

Space Complexity:
O(k)

The heap contains at most one node
from each linked list.
*/
class Solution {
public:
    struct compare {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,compare> pq;
        // Put the first node of every list
        // into the heap
        for (ListNode* list : lists) {
            if (list != nullptr) {
                pq.push(list);
            }
        }
        // Dummy node makes building the
        // result easier
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;
        while (!pq.empty()) {
            // Smallest current node
            ListNode* node = pq.top();
            pq.pop();
            // Add it to answer
            tail->next = node;
            tail = tail->next;
            // Add the next node from
            // the same list
            if (node->next != nullptr) {
                pq.push(node->next);
            }
        }
        return dummy->next;
    }
};