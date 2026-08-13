/*
House Robber III:

Use DFS + tree DP.

For every node, calculate 2 possibilities:

rob:
    Maximum money if we rob this node.
    Then we cannot rob either child.

skip:
    Maximum money if we skip this node.
    Then we can choose the best option from each child.

For a node:

rob = node->val + left.skip + right.skip

skip = max(left.rob, left.skip) + max(right.rob, right.skip)

Return both values from DFS.

Example:

        3
       / \
      2   3
       \   \
        3   1

At node 3:
    rob = 3 + best(skip left) + best(skip right)
    skip = best(left) + best(right)

Important:
    We need BOTH values for every node.
    Returning only one value loses information.

Main idea:
    Each node asks:
        "What is the best answer if I rob myself?"
        "What is the best answer if I skip myself?"

Base: nullptr -> {0, 0}

Time: O(N)
Visit every node once.

Space: O(H)
Recursion stack.
*/
class Solution {
public:
    pair<int, int> dfs(TreeNode* root) {
        if (root == nullptr) {
            return { 0, 0 };
        }
        // Get results from both children.
        pair<int, int> left = dfs(root->left);
        pair<int, int> right = dfs(root->right);
        // Rob current house:
        // Cannot rob either child.
        int rob = root->val + left.second + right.second;
        // Skip current house:
        // Choose the best option for each child.
        int skip = max(left.first, left.second) + max(right.first, right.second);
        return { rob, skip };
    }
    int rob(TreeNode* root) {
        pair<int, int> result = dfs(root);
        // Choose the better option for the root.
        return max(result.first, result.second);
    }
};