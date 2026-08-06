/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(nullptr) {}
 * };
 */
 /*
 Linked List Cycle Detection:

 Use Floyd's Cycle Detection
 (Tortoise and Hare).

 Maintain:

 slow

 Moves one node.

 fast

 Moves two nodes.

 While:

 fast != nullptr

 and

 fast->next != nullptr

 Move:

 slow = slow->next

 fast = fast->next->next

 If:

 slow == fast

 A cycle exists.

 Return true.

 If fast reaches nullptr:

 No cycle.

 Return false.

 Main insight:

 Once both pointers enter
 the cycle, the faster
 pointer gains one node
 per iteration and must
 eventually catch the
 slower pointer.

 Always compare node
 pointers, not node values.

 Time Complexity:

 O(n)

 Space Complexity:

 O(1)
 */
class Solution {
public:
    bool hasCycle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
                return true;
        }
        return false;
    }
};