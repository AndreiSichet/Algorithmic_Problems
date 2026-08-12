/*
Kth Smallest Integer in BST:

Use inorder DFS.

BST property: left < root < right

Inorder traversal: left -> root -> right

Therefore, inorder traversal of a BST visits values in ascending order.

Keep a counter: count = number of nodes visited.

When count == k: current node is the kth smallest.

Example:

        5
       / \
      3   7
     / \   \
    2   4   8

Inorder:
    2 -> 3 -> 4 -> 5 -> 7 -> 8

k = 3
answer = 4

Main idea: BST + inorder = sorted order.

Time: O(H + k) average
We stop once kth node is found.

Space: O(H)
Recursion stack.
*/
class Solution {
public:
    int count = 0;
    int answer = 0;
    void dfs(TreeNode* root, int k) {
        if (root == nullptr) {
            return;
        }
        // Visit left subtree first.
        dfs(root->left, k);
        // Visit current node.
        count++;
        if (count == k) {
            answer = root->val;
            return;
        }
        // Visit right subtree.
        dfs(root->right, k);
    }
    int kthSmallest(TreeNode* root, int k) {
        dfs(root, k);
        return answer;
    }
};