/*
Add Two Numbers:
The digits are stored in reverse order.
This is useful because we can perform normal addition starting from the ones digit.
At every position:
sum = digit1 + digit2 + carry
Then:
digit = sum % 10
carry = sum / 10
Create a new node containing digit and append it to the result.
If one list finishes before the other, treat its digit as 0.
Loop while:
l1 exists
OR
l2 exists
OR
carry exists
The carry condition is important because:
9 + 9 = 18
After both lists finish, we still need the final carry node 1.
Use a dummy node to simplify building the result.
Return:
dummy->next
Main insight:
This is just elementary addition with carry, and reverse-order storage lets us process the linked lists directly from left to right.
Time Complexity:
O(max(n, m))
Auxiliary Space:
O(1)
Output Space:
O(max(n, m))
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(nullptr) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;
        int carry = 0;
        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int x = (l1 != nullptr) ? l1->val : 0;
            int y = (l2 != nullptr) ? l2->val : 0;
            int sum = x + y + carry;
            carry = sum / 10;
            int digit = sum % 10;
            tail->next = new ListNode(digit);
            tail = tail->next;
            if (l1 != nullptr)
                l1 = l1->next;
            if (l2 != nullptr)
                l2 = l2->next;
        }
        return dummy->next;
    }
};