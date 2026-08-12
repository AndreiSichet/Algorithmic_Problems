/*
Construct Binary Tree from Preorder and Inorder:

Preorder: root -> left -> right

Inorder: left -> root -> right

Important observation:
    The first value in preorder is always the root of the current subtree.

After finding the root in inorder:
    everything to the left  = left subtree
    everything to the right = right subtree

Example:

preorder = [3,9,20,15,7]
inorder  = [9,3,15,20,7]

First preorder value: 3

So:
        3
       / \
      9   20

In inorder:
    [9] 3 [15,20,7]
     ^        ^
    left     right

Then recursively build both subtrees.

Use a hash map:
    value -> index in inorder

This lets us find the root position in O(1).

Main idea:
    preorder tells us WHICH node is root.
    inorder tells us HOW to split the tree.

Time: O(N)
Each node is processed once.

Space: O(N)
Hash map + recursion stack + tree.
*/
class Solution {
public:
    unordered_map<int, int> inMap;
    int preIndex = 0;
    TreeNode* build(vector<int>& preorder, int left, int right) {
        // No elements in this subtree.
        if (left > right) {
            return nullptr;
        }
        // First unused preorder value is the root.
        int rootValue = preorder[preIndex++];
        TreeNode* root = new TreeNode(rootValue);
        // Find root position in inorder.
        int mid = inMap[rootValue];
        // Everything left of mid belongs
        // to the left subtree.
        root->left = build(preorder, left, mid - 1);
        // Everything right of mid belongs
        // to the right subtree.
        root->right = build(preorder, mid + 1, right);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // Store each value's position in inorder.
        for (int i = 0; i < inorder.size(); i++) {
            inMap[inorder[i]] = i;
        }
        return build(preorder, 0, inorder.size() - 1);
    }
};