/*
Delete Leaves With Given Value:

Use postorder DFS:

    left -> right -> root

Why?
    A node can only be deleted if it is a leaf.
    Deleting its children may turn the current node into a leaf, so children must be processed first.

For every node:
    1. Recursively process left child.
    2. Recursively process right child.
    3. Update the child pointers.
    4. If current node is now a leaf and node->val == target, delete it.

Important:
    Check if the node is a leaf AFTER processing children.

Example:

        1
       /
      2
     /
    2

target = 2

First delete bottom 2:

        1
       /
      2

Now the parent 2 becomes a leaf,
so delete it too:

        1

This is why postorder is needed.

Base:
    nullptr -> nullptr

Time: O(N)
Visit every node once.

Space: O(H)
Recursion stack.
*/
class Solution {
public:
    TreeNode* dfs(TreeNode* root, int target) {
        if (root == nullptr) {
            return nullptr;
        }
        // Process children first.
        root->left = dfs(root->left, target);
        root->right = dfs(root->right, target);
        // Now check if current node became a leaf.
        if (root->left == nullptr && root->right == nullptr && root->val == target) {
            return nullptr;
        }
        return root;
    }
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        return dfs(root, target);
    }
};