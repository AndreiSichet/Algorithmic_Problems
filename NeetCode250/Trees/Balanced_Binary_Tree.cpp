#include <iostream>
#include<algorithm>
using namespace std;

/*
Balanced Binary Tree

A tree is balanced if, for EVERY node:

abs(leftHeight - rightHeight) <= 1


Main idea:
--------------------------------
For every node:

1. Get height of left subtree.
2. Get height of right subtree.
3. Check their difference.
4. Return the height of the current subtree.


Instead of calculating height separately
and then checking balance separately,
we do both in ONE DFS.

DFS returns:

- height, if the subtree is balanced
- -1, if the subtree is NOT balanced


Why -1?

A valid height can never be negative,
so -1 can be used as a signal:

-1 = subtree is not balanced


Example:

        1
       / \
      2   3
         /
        4

At node 4:
left = 0
right = 0
difference = 0
height = 1

At node 3:
left = 1
right = 0
difference = 1
height = 2

At node 2:
height = 1

At node 1:
leftHeight = 1
rightHeight = 2
difference = 1

Balanced.


Example of an unbalanced tree:

        1
       /
      2
     /
    3
   /
  4

At node 2:
leftHeight = 2
rightHeight = 0

difference = 2

So node 2 is not balanced.

Return -1.

That -1 travels back up to the root.


Base case:
nullptr -> height 0


Important:

The DFS does TWO jobs:

1. Calculate height.
2. Detect imbalance.


Time: O(N)
Every node is visited once.

Space: O(H)
H = tree height.
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
    int dfs(TreeNode* root) {
        // Empty subtree has height 0.
        if (root == nullptr) {
            return 0;
        }
        // Get height of left subtree.
        int leftHeight = dfs(root->left);
        // If left subtree is unbalanced, propagate -1 upward.
        if (leftHeight == -1) {
            return -1;
        }
        // Get height of right subtree.
        int rightHeight = dfs(root->right);
        // If right subtree is unbalanced, propagate -1 upward.
        if (rightHeight == -1) {
            return -1;
        }
        // Check current node.
        if (abs(leftHeight - rightHeight) > 1) {
            return -1;
        }
        // Return height of current subtree.
        return 1 + max(leftHeight, rightHeight);
    }
    bool isBalanced(TreeNode* root) {
        // -1 means the tree is unbalanced.
        return dfs(root) != -1;
    }
};
int main() {

    /*
            1
           / \
          2   3
             /
            4

        Balanced = true
    */

    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->right->left = new TreeNode(4);

    Solution solution;
    cout << boolalpha << solution.isBalanced(root) << endl;


    return 0;
}