/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(nullptr) {}
 * };
 */
 /*
 Reverse Linked List:

 Use three pointers:

 prev
 curr
 next

 Initially:

 prev = nullptr

 curr = head

 For every node:

 1. Save the next node.

 next = curr->next

 2. Reverse the link.

 curr->next = prev

 3. Move pointers.

 prev = curr

 curr = next

 Repeat until curr
 becomes nullptr.

 Return prev because
 it points to the
 new head.

 Main insight:

 Never reverse node
 values.

 Reverse the pointers.

 Always save the next
 node before changing
 curr->next, otherwise
 the rest of the list
 is lost.

 Time Complexity:

 O(n)

 Space Complexity:

 O(1)
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr != nullptr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};