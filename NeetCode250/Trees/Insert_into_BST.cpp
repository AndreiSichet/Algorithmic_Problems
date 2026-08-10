/*
Insert into a Binary Search Tree:

BST rule: left values < root < right values

Start at root and compare val with root->val.

If val < root->val:
    Go left.

If val > root->val:
    Go right.

When we reach a nullptr:
    This is where the new node belongs.
    Create the node and connect it.

If root is nullptr: The new node becomes the root.

Main idea:
Use the BST property to find the correct position without searching the whole tree.

Time: O(H)
Balanced BST: O(log N)
Worst case: O(N)

Space:
Iterative: O(1)
Recursive: O(H)
*/
#include <iostream>
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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        // Empty tree.
        if (root == nullptr) {
            return new TreeNode(val);
        }
        TreeNode* curr = root;
        while (true) {
            // New value belongs in the left subtree.
            if (val < curr->val) {
                // Found empty position.
                if (curr->left == nullptr) {
                    curr->left = new TreeNode(val);
                    break;
                }
                curr = curr->left;
            }
            // New value belongs in the right subtree.
            else {
                // Found empty position.
                if (curr->right == nullptr) {
                    curr->right = new TreeNode(val);
                    break;
                }
                curr = curr->right;
            }
        }
        return root;
    }
};
int main() {

    /*
            5
           / \
          3   9
         / \
        1   4

        Insert 6

        6 > 5
        -> go right

        6 < 9
        -> go left

        9 has no left child
        -> insert 6 there


            5
           / \
          3   9
         / \  /
        1   4 6
    */

    TreeNode* root = new TreeNode(5);

    root->left = new TreeNode(3);
    root->right = new TreeNode(9);

    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(4);

    int val = 6;

    Solution solution;

    root = solution.insertIntoBST(root, val);

    return 0;
}