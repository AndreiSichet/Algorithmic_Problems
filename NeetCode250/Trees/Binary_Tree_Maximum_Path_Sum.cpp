/*
Binary Tree Maximum Path Sum:

Use postorder DFS.

For every node, calculate:

1. gain:
   Maximum sum of a path starting at this node that can be continued through its parent.

2. maxPath:
   Maximum complete path found anywhere in the tree.

For a node:

leftGain  = max(0, dfs(left))
rightGain = max(0, dfs(right))

Why max(0)?
    A negative subtree only makes the path worse, so we ignore it.

A path passing THROUGH the current node can be:

    leftGain + root->val + rightGain

Update the global answer with this value.

But when returning to the parent, we CANNOT return both left and right branches.

The parent can only continue through one branch:

    gain = root->val + max(leftGain, rightGain)

Important distinction:

    Complete path:
        left + root + right

    Path returned to parent:
        root + one best child

Example:

        10
       /  \
      5    20
          /  \
         15   7

Path through 20:

    15 + 20 + 7 = 42

But 20 cannot return 42 to its parent,
because that would contain two branches.

It can only return:

    20 + max(15, 7) = 35

Main idea:
    DFS returns ONE branch.
    Global answer can use TWO branches.

Base:
    nullptr -> gain 0

Time: O(N)
    Every node visited once.

Space: O(H)
    Recursion stack.
*/
class Solution {
public:
    int maxSum = INT_MIN;
    int dfs(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        // Best contribution from left subtree.
        // Ignore it if it is negative.
        int leftGain = max(0, dfs(root->left));
        // Best contribution from right subtree.
        // Ignore it if it is negative.
        int rightGain = max(0, dfs(root->right));
        // Best complete path passing through this node.
        int currentPath = leftGain + root->val + rightGain;
        // This path could be the best anywhere in the tree.
        maxSum = max(maxSum, currentPath);
        // Return only ONE branch to the parent.
        return root->val + max(leftGain, rightGain);
    }
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return maxSum;
    }
};