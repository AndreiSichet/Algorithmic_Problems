/*
Copy Linked List with Random Pointer:
Each node has two pointers:next and random
Use a hash map: Original Node -> Copied Node
First pass:
Create a copy of every node.
Store:
mp[original] = copied
Second pass:
Connect pointers.
copy->next = mp[original->next]
copy->random = mp[original->random]
Return:
mp[head]
Main insight:
The hash map lets us immediately find the copy of any original node.
Without it, determining where random should point would require repeatedly searching the list, making the algorithm O(n^2).
Time Complexity:
O(n)
Space Complexity:
O(n)
*/
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr)
            return nullptr;
        unordered_map<Node*, Node*> mp;
        Node* curr = head;
        // First pass: create copies
        while (curr != nullptr) {
            mp[curr] = new Node(curr->val);
            curr = curr->next;
        }
        curr = head;
        // Second pass: connect pointers
        while (curr != nullptr) {
            mp[curr]->next = mp[curr->next];
            mp[curr]->random = mp[curr->random];
            curr = curr->next;
        }
        return mp[head];
    }
};