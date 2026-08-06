/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(nullptr) {}
 * };
 */
 /*
 Reorder Linked List:

 Pattern:

 Find Middle
 Reverse Second Half
 Merge Alternately

 Step 1:

 Use slow and fast pointers
 to find the middle.

 Disconnect the list:

 slow->next = nullptr

 Step 2:

 Reverse the second half
 using the standard
 three-pointer reversal:

 prev
 curr
 next

 Step 3:

 Merge both halves.

 Take one node from the
 first half,

 then one node from the
 reversed second half.

 Repeat until the second
 half is exhausted.

 Main insight:

 Instead of repeatedly
 taking the last node
 (O(n^2)),

 reverse the second half
 once,

 then merge in alternating
 order.

 This gives an O(n)
 solution.

 Time Complexity:

 O(n)

 Space Complexity:

 O(1)
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return;
        // Find middle
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        // Reverse second half
        ListNode* curr = slow->next;
        slow->next = nullptr;
        ListNode* prev = nullptr;
        while (curr != nullptr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        // Merge
        ListNode* first = head;
        ListNode* second = prev;
        while (second != nullptr) {
            ListNode* temp1 = first->next;
            ListNode* temp2 = second->next;
            first->next = second;
            second->next = temp1;
            first = temp1;
            second = temp2;
        }
    }
};