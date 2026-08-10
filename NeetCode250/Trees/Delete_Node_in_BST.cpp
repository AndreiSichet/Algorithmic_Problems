/*
Delete Node in a BST:

BST rule: left values < root < right values

Step 1: Search for key.

If key < root->val:
    Search left.

If key > root->val:
    Search right.

If key == root->val:
    We found the node to delete.

There are 3 deletion cases:

1. No children:
       5
      /
     3

Delete 3.
Just return nullptr.

2. One child:
       5
      /
     3
      \
       4

Delete 3.
Replace 3 with its child 4.


3. Two children:
       5
      /
     3
    / \
   1   4

We cannot simply delete 3 because
we would disconnect both children.

Find the smallest value in the RIGHT subtree.
This is called the inorder successor.

For node 3:
right subtree = 4
successor = 4

Replace 3's value with 4,
then delete the original 4.

Result:

       5
      /
     4
    /
   1


Main idea:

0 children -> return nullptr
1 child    -> return the child
2 children -> replace with inorder successor, then delete successor

The recursive return is important:

root->left = deleteNode(root->left, key);
root->right = deleteNode(root->right, key);

This reconnects the tree after deletion.

Time: O(H)
Balanced BST: O(log N)
Worst case: O(N)

Space: O(H) due to recursion.
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
    TreeNode* deleteNode(TreeNode* root, int key) {
        // Key was not found.
        if (root == nullptr) {
            return nullptr;
        }
        // Key is smaller, search left.
        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        }
        // Key is larger, search right.
        else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        }
        // key == root->val
        // We found the node.
        else {
            // Case 1:
            // No left child.
            // Return right child.
            if (root->left == nullptr) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }
            // Case 2:
            // No right child.
            // Return left child.
            if (root->right == nullptr) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }
            // Case 3:
            // Two children.
            // Find smallest node in right subtree.
            TreeNode* successor = root->right;
            while (successor->left != nullptr) {
                successor = successor->left;
            }
            // Copy successor's value.
            root->val = successor->val;
            // Delete the original successor.
            root->right = deleteNode( root->right, successor->val );
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

        Delete 3.

        3 has two children.

        Find smallest node in right subtree:
        right subtree of 3 = 4

        Replace 3 with 4:

            5
           / \
          4   9
         /
        1
    */

    TreeNode* root = new TreeNode(5);

    root->left = new TreeNode(3);
    root->right = new TreeNode(9);

    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(4);

    Solution solution;

    root = solution.deleteNode(root, 3);

    return 0;
}