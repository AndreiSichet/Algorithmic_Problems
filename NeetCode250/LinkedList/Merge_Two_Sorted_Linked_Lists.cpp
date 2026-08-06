/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(nullptr) {}
 * };
 */
 /*
 Merge Two Sorted Linked Lists:

 Use a dummy node to simplify
 building the answer.

 Maintain:

 tail

 which always points to
 the last node of the
 merged list.

 While both lists exist:

 Compare:

 list1->val

 list2->val

 Attach the smaller node
 to tail.

 Move:

 tail

 and the chosen list
 forward.

 After one list finishes,
 attach the remaining nodes
 from the other list.

 Return:

 dummy->next

 because dummy is only a
 helper node.

 Main insight:

 Do NOT create new nodes.

 Reuse the existing nodes
 by changing their next
 pointers.

 Time Complexity:

 O(m + n)

 Space Complexity:

 O(1)
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val <= list2->val) {
                tail->next = list1;
                list1 = list1->next;
            }
            else {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }
        if (list1 != nullptr)
            tail->next = list1;
        else
            tail->next = list2;
        return dummy->next;
    }
};