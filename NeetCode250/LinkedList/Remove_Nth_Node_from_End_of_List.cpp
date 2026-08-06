/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(nullptr) {}
 * };
 */
 /*
 Remove Nth Node From End:

 Use a dummy node to handle
 deleting the head easily.

 Maintain:

 slow
 fast

 Both start at the dummy.

 Move fast n+1 steps ahead
 to create a gap.

 Then move both pointers
 together until fast reaches
 nullptr.

 At that point:

 slow is immediately before
 the node to delete.

 Remove the node by:

 slow->next = slow->next->next;

 Return:

 dummy->next

 Main insight:

 Keeping a gap of n nodes
 lets slow stop exactly one
 node before the target,
 allowing deletion in one
 pass.

 Time Complexity:

 O(n)

 Space Complexity:

 O(1)
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* slow = dummy;
        ListNode* fast = dummy;
        // Move fast n+1 steps
        for (int i = 0; i <= n; i++)
            fast = fast->next;
        // Move together
        while (fast != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }
        // Delete node
        slow->next = slow->next->next;
        return dummy->next;
    }
};