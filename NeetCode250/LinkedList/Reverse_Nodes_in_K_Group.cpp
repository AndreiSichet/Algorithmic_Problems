/*
Reverse Nodes in K-Group:

Need:
Linked List + Pointer Manipulation.

Goal:
Reverse exactly k nodes at a time.

Example:
1 -> 2 -> 3 -> 4 -> 5 -> 6
k = 3

First group:
1 -> 2 -> 3
becomes:
3 -> 2 -> 1

Second group:
4 -> 5 -> 6
becomes:
6 -> 5 -> 4

Result:
3 -> 2 -> 1 -> 6 -> 5 -> 4


Main idea:
Process the list GROUP BY GROUP.

For each group:
1. Check if there are at least k nodes.
2. Find the kth node.
3. Save the node after the group.
4. Reverse the k nodes.
5. Connect the reversed group to the previous group.
6. Move to the next group.


Important pointers:

groupPrev:
The node BEFORE the current group.

groupStart:
The first node of the current group.

kth:
The last node of the current group.

groupNext:
The node AFTER the current group.

We MUST save groupNext before reversing,
because reversing changes the next pointers.


Example:

groupPrev
    |
    v
    1 -> 2 -> 3 -> 4 -> 5
    ^         ^
    |         |
groupStart   kth

groupNext = 4


Reverse the group:

1 <- 2 <- 3

Becomes:

3 -> 2 -> 1 -> 4 -> 5


After reversing:
groupPrev->next = kth

The old groupStart becomes the END
of the reversed group.

Then:

groupPrev = groupStart

This moves groupPrev to the end of
the reversed group so we can process
the next group.


If fewer than k nodes remain:
DO NOT reverse them.

Example:
1 -> 2 -> 3 -> 4 -> 5
k = 3

First group:
1 -> 2 -> 3
becomes:
3 -> 2 -> 1

Remaining:
4 -> 5

Only 2 nodes remain, so leave them unchanged.

Result:
3 -> 2 -> 1 -> 4 -> 5


Why use a dummy node?

Create:

dummy -> head

Start with:

groupPrev = dummy

This makes connecting the first reversed
group easier and avoids a special case
for the head.


Core reversal:

prev = groupNext
curr = groupStart

while curr != groupNext:

    temp = curr->next
    curr->next = prev
    prev = curr
    curr = temp

After the loop:

prev = new head of reversed group
groupStart = new tail of reversed group


Main insight:

Find k nodes
    |
    v
Save the next group
    |
    v
Reverse k nodes
    |
    v
Connect reversed group
    |
    v
Move to next group
    |
    v
Repeat


Important:
Save groupNext BEFORE reversing.

Otherwise, changing next pointers can
make us lose the connection to the rest
of the linked list.


Time Complexity:
O(N)

Every node is visited a constant number
of times.

Space Complexity:
O(1)

Only pointers are used.
No extra array, stack, or list is needed.
*/
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        // Dummy node before the actual head.
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        // Node before the current group.
        ListNode* groupPrev = dummy;
        while (true) {
            // Find the kth node of the current group.
            ListNode* kth = groupPrev;
            for (int i = 0; i < k; i++) {
                kth = kth->next;
                // Fewer than k nodes remain.
                // Leave them unchanged.
                if (kth == nullptr) {
                    return dummy->next;
                }
            }
            // First node of the current group.
            ListNode* groupStart = groupPrev->next;
            // Save the node after the group.
            ListNode* groupNext = kth->next;
            // Reverse the current group.
            ListNode* prev = groupNext;
            ListNode* curr = groupStart;
            while (curr != groupNext) {
                ListNode* temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
            }
            // Connect the previous group
            // to the new head of this group.
            groupPrev->next = kth;
            // The old first node is now the last node
            // of the reversed group.
            groupPrev = groupStart;
        }
    }
};