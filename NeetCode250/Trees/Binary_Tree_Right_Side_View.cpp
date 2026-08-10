/*
Binary Tree Right Side View:

Use BFS with a queue.

Process the tree level by level.

For every level:
    size = number of nodes in current level

    Process all size nodes.

    The LAST node processed is the rightmost node of that level.

    Add it to the answer.

Example:

        1
       / \
      2   3
       \   \
        4   5

Level 1:
    [1]
    rightmost = 1

Level 2:
    [2,3]
    rightmost = 3

Level 3:
    [4,5]
    rightmost = 5

Answer:
    [1,3,5]

Important:
Use size = q.size() so we know where the current level ends.

At:
    i == size - 1

we are processing the rightmost node.

Time: O(N)
Space: O(N)
*/
#include <bits/stdc++.h>
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if (root == nullptr) {
            return result;
        }
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode* curr = q.front();
                q.pop();
                // Last node of this level.
                if (i == size - 1) {
                    result.push_back(curr->val);
                }
                if (curr->left != nullptr) {
                    q.push(curr->left);
                }
                if (curr->right != nullptr) {
                    q.push(curr->right);
                }
            }
        }
        return result;
    }
};