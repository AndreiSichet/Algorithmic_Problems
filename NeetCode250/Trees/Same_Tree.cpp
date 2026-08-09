#include <iostream>
using namespace std;

/*
Same Binary Tree

Two trees are the same if:

1. Their current nodes have the same value.
2. Their left subtrees are the same.
3. Their right subtrees are the same.


Example:

        1               1
       / \             / \
      2   3           2   3

Compare:
1 == 1
2 == 2
3 == 3

Both structure and values match.


Recursive DFS:
--------------------------------

isSame(p, q)

1. Both nullptr:
   return true

2. One nullptr:
   return false

3. Values are different:
   return false

4. Recursively compare:
   left subtrees
   right subtrees

Return:

isSame(p->left, q->left)
AND
isSame(p->right, q->right)


Important:
We traverse BOTH trees at the same time.


Example of different structure:

        4               4
       /                 \
      7                   7

At root:
4 == 4

Then compare left:

p->left = 7
q->left = nullptr

One is nullptr and the other is not.

Therefore:
false


Time: O(N)
Each corresponding node is checked once.

Space: O(H)
H = height of the tree.
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // Both trees are empty at this position.
        if (p == nullptr && q == nullptr) {
            return true;
        }
        // One is empty, the other is not.
        if (p == nullptr || q == nullptr) {
            return false;
        }
        // Values are different.
        if (p->val != q->val) {
            return false;
        }
        // Compare left and right subtrees.
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
int main() {

    /*
            p               q

            1               1
           / \             / \
          2   3           2   3

        Expected: true
    */

    TreeNode* p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(3);

    TreeNode* q = new TreeNode(1);
    q->left = new TreeNode(2);
    q->right = new TreeNode(3);


    Solution solution;

    cout << boolalpha << solution.isSameTree(p, q) << endl;


    return 0;
}