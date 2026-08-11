/*
Count Good Nodes in Binary Tree:

Use DFS.

For every node, keep track of: maxVal = largest value seen from root to the current node.

A node is good if:
    node->val >= maxVal

If good:
    count it.

Then update maxVal:
    maxVal = max(maxVal, node->val)

Pass the updated maxVal to both children.

Example:

        3
       / \
      1   4
         / \
        2   5

Path to 4:
    3 -> 4
    maxVal = 3
    4 >= 3 -> good

Path to 2:
    3 -> 4 -> 2
    maxVal = 4
    2 < 4 -> not good

Path to 5:
    3 -> 4 -> 5
    maxVal = 4
    5 >= 4 -> good

Good nodes:
    3, 4, 5

Answer = 3

Main idea:
DFS moves down the tree while carrying the maximum value seen on the current path.

Base case:
    root == nullptr -> return 0

Time: O(N)
Visit every node once.

Space: O(H)
Recursion stack.
*/
#include <iostream>
#include<algorithm>
using namespace std;
/*
Definition for a binary tree node.

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};
*/
class Solution {
public:
    int dfs(TreeNode* root, int maxVal) {
        // Empty subtree.
        if (root == nullptr) {
            return 0;
        }
        int count = 0;
        // Check if current node is good.
        if (root->val >= maxVal) {
            count = 1;
        }
        // Update maximum for this path.
        maxVal = max(maxVal, root->val);
        // Search both subtrees.
        count += dfs(root->left, maxVal);
        count += dfs(root->right, maxVal);
        return count;
    }
    int goodNodes(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        // Root is always good.
        return dfs(root, root->val);
    }
};