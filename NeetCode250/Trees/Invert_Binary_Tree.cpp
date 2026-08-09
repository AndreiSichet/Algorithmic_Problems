#include <iostream>
using namespace std;

/*
Invert Binary Tree

Goal:
Swap the left and right child of every node.

Example:

        1
       / \
      2   3
     / \ / \
    4  5 6  7

After inversion:

        1
       / \
      3   2
     / \ / \
    7  6 5  4


For every node:

1. Swap left and right.
2. DFS left.
3. DFS right.

Base case:
root == nullptr -> return


Important:
We do NOT need to create new nodes.

Just swap the two pointers:

temp = root->left
root->left = root->right
root->right = temp


Why does recursion work?

After swapping the current node,
we recursively invert both subtrees.

The same operation is applied to every node.


Time: O(N)
Every node is visited once.

Space: O(H)
H = height of tree.

Worst case: O(N)
Balanced tree: O(log N)


Main insight:

Invert one node:
    swap(left, right)

Then do the same thing
for every node using DFS.
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

    void dfs(TreeNode* root) {
        // Base case
        if (root == nullptr) {
            return;
        }
        // Swap left and right.
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;
        // Invert left subtree.
        dfs(root->left);
        // Invert right subtree.
        dfs(root->right);
    }
    TreeNode* invertTree(TreeNode* root) {
        dfs(root);
        return root;
    }
};


int main() {

    /*
            1
           / \
          2   3
         / \ / \
        4  5 6  7

        After inversion:

            1
           / \
          3   2
         / \ / \
        7  6 5  4
    */

    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);


    Solution solution;

    solution.invertTree(root);


    return 0;
}