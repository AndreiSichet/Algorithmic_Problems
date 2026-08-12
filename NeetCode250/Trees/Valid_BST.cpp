/*
Valid Binary Search Tree:

Use DFS with a valid range [minVal, maxVal].

For every node: node->val must be strictly between minVal and maxVal.

For the left child:
    values must be smaller than current node.
    range becomes [minVal, node->val]

For the right child:
    values must be greater than current node.
    range becomes [node->val, maxVal]

Important:
    Use strict inequalities.
    Duplicate values are not allowed.

Example:

        5
       / \
      3   8
     / \
    1   4

For 5:
    range = (-inf, +inf)

For 3:
    range = (-inf, 5)

For 8:
    range = (5, +inf)

For 1:
    range = (-inf, 3)

For 4:
    range = (3, 5)

If a node falls outside its range:
    return false.

Base case: root == nullptr -> true

Time: O(N)
Visit every node once.

Space: O(H)
Recursion stack.
*/
class Solution {
public:
    bool dfs(TreeNode* root, long long minVal, long long maxVal) {
        // Empty tree/subtree is valid.
        if (root == nullptr) {
            return true;
        }
        // Current value must be inside the valid range.
        if (root->val <= minVal || root->val >= maxVal) {
            return false;
        }
        // Left subtree:
        // every value must be smaller than root->val.
        bool left = dfs(root->left, minVal, root->val);
        // Right subtree:
        // every value must be greater than root->val.
        bool right = dfs(root->right, root->val, maxVal);
        return left && right;
    }
    bool isValidBST(TreeNode* root) {
        return dfs(root, LLONG_MIN, LLONG_MAX);
    }
};