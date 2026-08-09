#include <iostream>
#include<vector>
#include<stack>
using namespace std;

/*
Binary Tree Postorder Traversal

Postorder:
LEFT -> RIGHT -> ROOT

Example:

        1
       / \
      2   3
     / \  / \
    4  5 6  7

Result:
4 5 2 6 7 3 1


Solution 1: Recursive DFS
--------------------------------
For every node:

1. Visit LEFT
2. Visit RIGHT
3. Process ROOT

Base case:
root == nullptr -> return

Time: O(N)
Space: O(H)


Solution 2: Iterative DFS
--------------------------------
Use a stack to simulate recursion.

Postorder is harder because ROOT must be
processed after both children.

Simple approach:

1. Use a stack.
2. Process nodes in:
   ROOT -> RIGHT -> LEFT
3. Reverse the result.

Why?

Reverse of:

ROOT -> RIGHT -> LEFT

is:

LEFT -> RIGHT -> ROOT

which is exactly postorder.

Time: O(N)
Space: O(N)


Main difference:

Recursive:
Directly follows LEFT -> RIGHT -> ROOT.

Iterative:
Uses ROOT -> RIGHT -> LEFT,
then reverses the result.


Remember:

Preorder:
ROOT -> LEFT -> RIGHT

Inorder:
LEFT -> ROOT -> RIGHT

Postorder:
LEFT -> RIGHT -> ROOT
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
        // RIGHT
        dfs(root->right, result);
        // ROOT
        result.push_back(root->val);
    }
    vector<int> postorderRecursive(TreeNode* root) {
        vector<int> result;
        dfs(root, result);
        return result;
    }

    // =========================================================
    // Solution 2: Iterative DFS
    // =========================================================

    vector<int> postorderIterative(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> st;
        if (root == nullptr) {
            return result;
        }
        st.push(root);
        while (!st.empty()) {
            TreeNode* curr = st.top();
            st.pop();
            // Process ROOT first.
            result.push_back(curr->val);
            // Push LEFT first.
            if (curr->left != nullptr) {
                st.push(curr->left);
            }
            // Push RIGHT second.
            if (curr->right != nullptr) {
                st.push(curr->right);
            }
        }

        // Current order:
        // ROOT -> RIGHT -> LEFT
        //
        // Reverse it:
        // LEFT -> RIGHT -> ROOT

        reverse(result.begin(), result.end());
        return result;
    }
};
int main() {

    /*
            1
           / \
          2   3
         / \  / \
        4  5 6  7

        Expected:
        4 5 2 6 7 3 1
    */

    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);


    Solution solution;


    // Recursive DFS
    vector<int> recursiveResult =
        solution.postorderRecursive(root);

    cout << "Recursive: ";

    for (int x : recursiveResult) {
        cout << x << " ";
    }

    cout << endl;


    // Iterative DFS
    vector<int> iterativeResult =
        solution.postorderIterative(root);

    cout << "Iterative: ";

    for (int x : iterativeResult) {
        cout << x << " ";
    }

    cout << endl;


    return 0;
}