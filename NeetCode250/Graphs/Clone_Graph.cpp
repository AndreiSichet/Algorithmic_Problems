/*
Clone Graph:

Use DFS + a hash map.

The graph can contain cycles.

Example:

    1 ----- 2
    |       |
    |       |
    4 ----- 3

If we simply perform DFS without remembering
which nodes we already cloned, we could loop:

    1 -> 2 -> 3 -> 4 -> 1 -> 2 -> ...

So we use:

    unordered_map<Node*, Node*>

The map stores:

    original node -> cloned node

When we visit a node:

    1. Check if it was already cloned.
    2. If yes, return the existing clone.
    3. If no, create a new node.
    4. Store it in the map.
    5. Recursively clone all neighbors.
    6. Add the cloned neighbors to the clone.

The order is important.

We must store the clone in the map BEFORE
recursively cloning its neighbors.

Example:

    1 -> 2 -> 1

When cloning 1:

    create 1'
    map[1] = 1'

Then clone 2.

When 2 tries to clone 1 again:

    map already contains 1 -> 1'

So we return 1' instead of creating another node.

This prevents infinite recursion and also ensures
that every original node has exactly one clone.

Time:
    O(V + E)

Each node and edge is processed once.

Space:
    O(V)

The map stores one clone for every node.

The recursion stack can also be O(V).
*/

class Solution {
private:
    unordered_map<Node*, Node*> clones;
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) {
            return nullptr;
        }
        // Return the existing clone if this node was visited.
        if (clones.count(node)) {
            return clones[node];
        }
        // Create and store the clone before visiting neighbors.
        Node* copy = new Node(node->val);
        clones[node] = copy;
        for (Node* neighbor : node->neighbors) {
            copy->neighbors.push_back(cloneGraph(neighbor));
        }
        return copy;
    }
};