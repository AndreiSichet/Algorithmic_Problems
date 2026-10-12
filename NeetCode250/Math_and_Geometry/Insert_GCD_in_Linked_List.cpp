/*
LINKED LIST TRAVERSAL + GCD - INSERT GREATEST COMMON DIVISORS IN LINKED LIST

Goal:
- Insert a new node between every pair of adjacent nodes.
- Each inserted node must contain the GCD of the two original adjacent values.
- Return the head of the modified linked list.

Key idea:
- Traverse the linked list one adjacent pair at a time.
- For each pair, calculate their GCD using the Euclidean algorithm.
- Insert a new node between the current node and its original next node.
- Advance to the next original node, skipping the inserted node.

Algorithm:
1. Start at the head of the linked list.
2. While the current node and its next node both exist:
   - Save the next original node.
   - Calculate gcd(current->val, next->val).
   - Create a new node containing that GCD.
   - Link the new node after the current node.
   - Link the new node to the saved next original node.
   - Move current to the saved next original node.
3. Return head.

Why this works:
- Every pair of adjacent original nodes is processed exactly once.
- The GCD is inserted between the two nodes that produced it.
- Advancing to the saved original next node prevents processing inserted
  nodes as if they were part of the original list.
- The original nodes remain in their original order, with exactly one
  GCD node inserted between each adjacent pair.

Important boundaries:
- If the list contains only one node, no insertion is needed.
- If the list is empty, return nullptr.
- Use the saved next original node when advancing, otherwise the algorithm
  could process newly inserted nodes and produce incorrect results.
- The Euclidean algorithm calculates GCD efficiently:
  gcd(a, b) = gcd(b, a % b), until b becomes 0.

Complexity:
- Time: O(n log M), where n is the number of original nodes and M is
  the maximum node value. Each adjacent pair requires one GCD calculation.
- Space: O(n) for the newly allocated nodes; O(1) auxiliary space,
  excluding the nodes created for the result.
*/

class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* current = head;
        while (current != nullptr && current->next != nullptr) {
            ListNode* nextNode = current->next;
            int gcdValue = gcd(current->val, nextNode->val);
            current->next = new ListNode(gcdValue);
            current->next->next = nextNode;
            current = nextNode;
        }
        return head;
    }
};