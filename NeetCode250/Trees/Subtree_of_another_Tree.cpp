#include <iostream>
using namespace std;

/*
Subtree of Another Tree

Goal:
Check if subRoot appears inside root as an
exact subtree.

A subtree must have:
1. Same structure.
2. Same node values.

Main idea:
--------------------------------
Use TWO recursive functions.

1. isSame(p, q)
   Checks if two trees are exactly the same.

2. dfs(root, subRoot)
   Searches every node in root.

At every node:

If current subtree == subRoot:
    return true

Otherwise:
    search left subtree
    search right subtree


Example:

        1
       / \
      2   3
     / \
    4   5

subRoot:

      2
     / \
    4   5


Start at 1:
1 != 2
Search left.

Start at 2:
2 == 2

Now use isSame():

    2           2
   / \         / \
  4   5       4   5

Everything matches.

Return true.


Important:
We do NOT compare only values.

The entire structure must match.

Example:

root:
    2
   /
  4

subRoot:
    2
   / \
  4   5

These are NOT the same.


Time: O(N * M)
N = number of nodes in root
M = number of nodes in subRoot

Space: O(H)
H = recursion depth.
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
    // Checks if two trees are exactly the same.
    bool isSame(TreeNode* p, TreeNode* q) {
        // Both are empty.
        if (p == nullptr && q == nullptr) {
            return true;
        }
        // Only one is empty.
        if (p == nullptr || q == nullptr) {
            return false;
        }
        // Values are different.
        if (p->val != q->val) {
            return false;
        }
        // Compare both subtrees.
        return isSame(p->left, q->left) &&
            isSame(p->right, q->right);
    }
    // Searches root for subRoot.
    bool dfs(TreeNode* root, TreeNode* subRoot) {
        // No tree left to search.
        if (root == nullptr) {
            return false;
        }
        // Current subtree matches.
        if (isSame(root, subRoot)) {
            return true;
        }
        // Search left or right subtree.
        return dfs(root->left, subRoot) || dfs(root->right, subRoot);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return dfs(root, subRoot);
    }
};


int main() {

    /*
            root:

                1
               / \
              2   3
             / \
            4   5

            subRoot:

                2
               / \
              4   5

            Expected:
            true
    */

    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);


    TreeNode* subRoot = new TreeNode(2);

    subRoot->left = new TreeNode(4);
    subRoot->right = new TreeNode(5);


    Solution solution;

    cout << boolalpha
        << solution.isSubtree(root, subRoot)
        << endl;


    return 0;
}   