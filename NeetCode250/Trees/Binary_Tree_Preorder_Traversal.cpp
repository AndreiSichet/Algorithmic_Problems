#include <iostream>
#include<vector>
#include<stack>
using namespace std;
/*
Binary Tree Preorder Traversal

Preorder:
ROOT -> LEFT -> RIGHT

Example:

        1
       / \
      2   3
     / \  /
    4  5 6

Result:
1 2 4 5 3 6


Solution 1: Recursive DFS
--------------------------------
For every node:

1. Process ROOT
2. Visit LEFT
3. Visit RIGHT

Base case:
root == nullptr -> return

Time: O(N)
Space: O(H)


Solution 2: Iterative DFS
--------------------------------
Use a stack to simulate recursion.

1. Push root.
2. Pop a node and process it.
3. Push RIGHT child.
4. Push LEFT child.

Why RIGHT first?

Stack is LIFO.
We want LEFT to be processed first.

So:

Push RIGHT
Push LEFT

Then LEFT comes out first.

Time: O(N)
Space: O(H)


Main difference:

Recursive:
Call stack handles the traversal.

Iterative:
We manually use a stack.


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
        // ROOT
        result.push_back(root->val);
        // LEFT
        dfs(root->left, result);
        // RIGHT
        dfs(root->right, result);
    }
    vector<int> preorderRecursive(TreeNode* root) {
        vector<int> result;
        dfs(root, result);
        return result;
    }

    // =========================================================
    // Solution 2: Iterative DFS
    // =========================================================

    vector<int> preorderIterative(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> st;
        if (root == nullptr) {
            return result;
        }
        st.push(root);
        while (!st.empty()) {
            // Get current node.
            TreeNode* curr = st.top();
            st.pop();
            // ROOT
            result.push_back(curr->val);
            // Push RIGHT first.
            if (curr->right != nullptr) {
                st.push(curr->right);
            }
            // Push LEFT second.
            if (curr->left != nullptr) {
                st.push(curr->left);
            }
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
        1 2 4 5 3 6
    */

    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    root->right->left = new TreeNode(6);


    Solution solution;


    // Recursive DFS
    vector<int> recursiveResult = solution.preorderRecursive(root);

    cout << "Recursive: ";

    for (int x : recursiveResult) {
        cout << x << " ";
    }

    cout << endl;


    // Iterative DFS
    vector<int> iterativeResult =  solution.preorderIterative(root);

    cout << "Iterative: ";

    for (int x : iterativeResult) {
        cout << x << " ";
    }

    cout << endl;


    return 0;
}