#include <iostream>
using namespace std;
/*
Lowest Common Ancestor in a BST

BST property:

left subtree  <  root  <  right subtree

We have two nodes: p and q.

At every node, compare p and q with root.

Case 1:
Both p and q are smaller than root.

    p < root
    q < root

Therefore LCA must be in the LEFT subtree.


Case 2:
Both p and q are larger than root.

    p > root
    q > root

Therefore LCA must be in the RIGHT subtree.


Case 3:
p and q are on different sides.

    p < root < q

or

    q < root < p

Then root is the LCA.


Case 4:
root == p or root == q

The current node is the LCA because
a node is allowed to be an ancestor of itself.


Example:

        5
       / \
      3   8
     / \
    1   4

p = 3
q = 4

At 5:
3 < 5
4 < 5

Both are smaller.
Go LEFT.

At 3:
p = 3
q = 4

One node is the current node.
Therefore 3 is the LCA.


Main insight:

Use the BST property to decide which direction to move.

We never need to visit irrelevant parts of the tree.

Time: O(H)
H = height of tree.

Balanced BST: O(log N)
Worst case: O(N)

Space: O(1) for iterative solution.
*/


struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = nullptr;
        right = nullptr;
    }
};


class Solution {
public:
    TreeNode* lowestCommonAncestor( TreeNode* root, TreeNode* p, TreeNode* q ) {
        while (root != nullptr) {
            // Both nodes are smaller.
            // LCA must be on the left.
            if (p->val < root->val && q->val < root->val) {
                root = root->left;
            }
            // Both nodes are larger.
            // LCA must be on the right.
            else if (p->val > root->val && q->val > root->val) {
                root = root->right;
            }
            // Split point or root == p/q.
            else {
                return root;
            }
        }
        return nullptr;
    }
};
int main() {

    /*
            5
           / \
          3   8
         / \ / \
        1  4 7  9

        p = 3
        q = 8

        LCA = 5
    */

    TreeNode* root = new TreeNode(5);

    root->left = new TreeNode(3);
    root->right = new TreeNode(8);

    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(4);

    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);

    TreeNode* p = root->left;
    TreeNode* q = root->right;

    Solution solution;

    TreeNode* answer = solution.lowestCommonAncestor(root, p, q);

    cout << answer->val << endl;

    return 0;
}