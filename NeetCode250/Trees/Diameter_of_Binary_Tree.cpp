#include <bits/stdc++.h>
using namespace std;

/*
Diameter of Binary Tree

Diameter = longest path between any two nodes.

The length is measured in EDGES, not nodes.


Example:

        1
         \
          2
         / \
        3   4
       /
      5

Longest path:

5 -> 3 -> 2 -> 4

There are 3 edges.

Diameter = 3


Main idea:
--------------------------------
For every node, calculate its height.

If we are currently at a node:

leftHeight  = height of left subtree
rightHeight = height of right subtree

A path passing through the current node is:

leftHeight + rightHeight

Why?

Example:

        node
       /    \
      A      B

The longest path through node goes:

deepest node in A
        |
        |
      node
        |
        |
deepest node in B

Number of edges:
leftHeight + rightHeight


But the diameter does NOT necessarily pass
through the root.

So at every node we update a global answer:

diameter = max(diameter, leftHeight + rightHeight)


The DFS still needs to return the HEIGHT.

Height of current node:

1 + max(leftHeight, rightHeight)


Important distinction:

DFS RETURNS:
height

DFS UPDATES:
diameter


Example:

        1
         \
          2
         / \
        3   4
       /
      5

At node 3:
leftHeight = 1
rightHeight = 0

diameter through 3 = 1


At node 2:
leftHeight = 2
rightHeight = 1

diameter through 2 = 3

So answer becomes 3.


Base case:
nullptr -> height 0


Time: O(N)
Every node is visited once.

Space: O(H)
H = height of tree.
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
    int diameter = 0;
    int dfs(TreeNode* root) {
        // Empty subtree has height 0.
        if (root == nullptr) {
            return 0;
        }
        // Get height from left subtree.
        int leftHeight = dfs(root->left);
        // Get height from right subtree.
        int rightHeight = dfs(root->right);
        /*
        Longest path passing through the current node.
        leftHeight and rightHeight
        represent the number of edges
        going down each side.
        */
        diameter = max( diameter, leftHeight + rightHeight );
        /*
        Return height to the parent.
        The parent can only continue
        through ONE side of this node,
        so we take the larger side.
        */
        return 1 + max( leftHeight, rightHeight );
    }
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return diameter;
    }
};


int main() {

    /*
            1
             \
              2
             / \
            3   4
           /
          5

        Longest path:

        5 -> 3 -> 2 -> 4

        Diameter = 3
    */

    TreeNode* root = new TreeNode(1);

    root->right = new TreeNode(2);

    root->right->left = new TreeNode(3);
    root->right->right = new TreeNode(4);

    root->right->left->left = new TreeNode(5);


    Solution solution;

    cout << solution.diameterOfBinaryTree(root) << endl;


    return 0;
}