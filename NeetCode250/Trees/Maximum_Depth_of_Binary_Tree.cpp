#include <bits/stdc++.h>
using namespace std;

/*
Maximum Depth of Binary Tree

Goal:
Find the number of nodes on the longest path
from the root to a leaf.


Example:

        1
       / \
      2   3
         /
        4

Longest path:

1 -> 3 -> 4

Depth = 3


Solution 1: Recursive DFS
--------------------------------
For every node:

1. Find depth of left subtree.
2. Find depth of right subtree.
3. Take the larger depth.
4. Add 1 for the current node.

Formula:

depth = 1 + max(leftDepth, rightDepth)


Base case:
root == nullptr -> return 0


Example:

        1
       / \
      2   3
         /
        4

At node 4:
left = 0
right = 0
depth = 1

At node 3:
left = 1
right = 0
depth = 2

At node 1:
left = 1
right = 2
depth = 3


Time: O(N)
Every node is visited once.

Space: O(H)
H = height of tree.


Solution 2: Iterative BFS
--------------------------------
Use a queue and process the tree
level by level.

Each level represents one depth.

Example:

        1          Level 1
       / \
      2   3        Level 2
         /
        4          Level 3

Algorithm:

1. Put root in queue.
2. Process all nodes in the current level.
3. Add their children to the queue.
4. Increase depth by 1.
5. Repeat until queue is empty.

Time: O(N)

Space: O(W)
W = maximum width of tree.


Main insight:

DFS:
depth = 1 + max(left, right)

BFS:
number of levels = depth
*/


struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = nullptr;
        right = nullptr;
    }
};


class Solution {
public:

    // =========================================================
    // Solution 1: Recursive DFS
    // =========================================================

    int maxDepthDFS(TreeNode* root) {

        // Empty tree has depth 0.
        if (root == nullptr) {
            return 0;
        }

        int leftDepth = maxDepthDFS(root->left);
        int rightDepth = maxDepthDFS(root->right);

        return 1 + max(leftDepth, rightDepth);
    }


    // =========================================================
    // Solution 2: Iterative BFS
    // =========================================================

    int maxDepthBFS(TreeNode* root) {

        if (root == nullptr) {
            return 0;
        }

        queue<TreeNode*> q;
        q.push(root);

        int depth = 0;

        while (!q.empty()) {

            // Number of nodes in the current level.
            int levelSize = q.size();

            // Process one complete level.
            for (int i = 0; i < levelSize; i++) {

                TreeNode* curr = q.front();
                q.pop();

                if (curr->left != nullptr) {
                    q.push(curr->left);
                }

                if (curr->right != nullptr) {
                    q.push(curr->right);
                }
            }

            // Finished one level.
            depth++;
        }

        return depth;
    }
};


int main() {

    /*
            1
           / \
          2   3
             /
            4

        Expected:
        3
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    Solution solution;
    cout << "DFS: " << solution.maxDepthDFS(root) << endl;
    cout << "BFS: " << solution.maxDepthBFS(root) << endl;
    return 0;
}