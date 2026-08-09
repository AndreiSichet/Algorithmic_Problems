#include <iostream>
#include<vector>
#include<stack>
using namespace std;
/*
Binary Tree Inorder Traversal

Inorder:
LEFT -> ROOT -> RIGHT

Example:

        1
       / \
      2   3
     / \  /
    4  5 6

Result:
4 2 5 1 6 3


Solution 1: Recursive DFS
--------------------------------
Use recursion to naturally follow:

1. Visit left subtree
2. Process current node
3. Visit right subtree

Base case:
root == nullptr -> return

Time: O(N)
Space: O(H)
H = tree height


Solution 2: Iterative DFS
--------------------------------
Use a stack to simulate recursion.

1. Keep going left and push nodes.
2. When there is no left node:
   - Pop from stack.
   - Process node.
   - Move to right subtree.
3. Repeat until both curr == nullptr
   and stack is empty.

Time: O(N)
Space: O(H)

Main difference:

Recursive:
Call stack handles the nodes.

Iterative:
We manually use a stack.
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

    void dfs(TreeNode* root, vector<int>& result) {
        // Base case
        if (root == nullptr) {
            return;
        }
        // LEFT
        dfs(root->left, result);
        // ROOT
        result.push_back(root->val);
        // RIGHT
        dfs(root->right, result);
    }
    vector<int> inorderRecursive(TreeNode* root) {
        vector<int> result;
        dfs(root, result);
        return result;
    }

    // =========================================================
    // Solution 2: Iterative DFS
    // =========================================================

    vector<int> inorderIterative(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> st;
        TreeNode* curr = root;
        while (curr != nullptr || !st.empty()) {
            // Keep going LEFT.
            while (curr != nullptr) {
                st.push(curr);
                curr = curr->left;
            }
            // Process ROOT.
            curr = st.top();
            st.pop();
            result.push_back(curr->val);
            // Move RIGHT.
            curr = curr->right;
        }
        return result;
    }
};
int main() {

    /*
            1
           / \
          2   3
         / \  /
        4  5 6

        Expected:
        4 2 5 1 6 3
    */

    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    root->right->left = new TreeNode(6);


    Solution solution;


    // Recursive DFS
    vector<int> recursiveResult =
        solution.inorderRecursive(root);

    cout << "Recursive: ";

    for (int x : recursiveResult) {
        cout << x << " ";
    }

    cout << endl;


    // Iterative DFS
    vector<int> iterativeResult =
        solution.inorderIterative(root);

    cout << "Iterative: ";

    for (int x : iterativeResult) {
        cout << x << " ";
    }

    cout << endl;


    return 0;
}