/*
Binary Tree Level Order Traversal:

Use BFS with a queue.

Why queue?
A queue is FIFO: first node added = first node processed.

Start:
    put root into queue.

For each level:
    1. Get the number of nodes currently in queue.
    2. Process exactly that many nodes.
    3. Add their children to the queue.
    4. Store the values in one vector.

Example:

        1
       / \
      2   3
     / \ / \
    4  5 6  7

Queue:

Start:
[1]

Process 1:
result = [1]
queue = [2,3]

Process 2 and 3:
result = [2,3]
queue = [4,5,6,7]

Process 4,5,6,7:
result = [4,5,6,7]
queue = []

Final:
[[1],[2,3],[4,5,6,7]]

Important:
int size = q.size();

This tells us exactly how many nodes belong to the CURRENT level.

Do not use q.size() directly as the loop condition because the queue changes when children are added.

Time: O(N)
Space: O(N)
*/
#include <iostream>
#include<queue>
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == nullptr) {
            return result;
        }
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            // Number of nodes in the current level.
            int size = q.size();
            vector<int> level;
            for (int i = 0; i < size; i++) {
                TreeNode* curr = q.front();
                q.pop();
                level.push_back(curr->val);
                if (curr->left != nullptr) {
                    q.push(curr->left);
                }
                if (curr->right != nullptr) {
                    q.push(curr->right);
                }
            }
            result.push_back(level);
        }
        return result;
    }
};