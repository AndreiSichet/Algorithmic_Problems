/*
Serialize and Deserialize Binary Tree:

Use preorder DFS:

    root -> left -> right

Serialization:
    Convert every node to its value.
    Use a special marker for nullptr.

Example:

        1
       / \
      2   3
         / \
        4   5

Serialize:

    1,2,N,N,3,4,N,N,5,N,N

Why store N?
    Without nullptr markers, we would lose the
    structure of the tree.

Deserialize:
    Read the values in the same preorder order.

    If value == N:
        return nullptr

    Otherwise:
        create node
        recursively build left
        recursively build right

The exact same order used during serialization must be used during deserialization.

Time: O(N)
    Every node is processed once.

Space: O(N)
    String + recursion/queue used for reconstruction.
*/
class Codec {
public:
    // Serialize tree into a string.
    string serialize(TreeNode* root) {
        if (root == nullptr) {
            return "N,";
        }
        return to_string(root->val) + "," + serialize(root->left) + serialize(root->right);
    }
    // Deserialize string back into a tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return buildTree(ss);
    }
private:
    TreeNode* buildTree(stringstream& ss) {
        string value;
        getline(ss, value, ',');
        // Null marker.
        if (value == "N") {
            return nullptr;
        }
        // Create current node.
        TreeNode* root = new TreeNode(stoi(value));
        // Build left subtree.
        root->left = buildTree(ss);
        // Build right subtree.
        root->right = buildTree(ss);
        return root;
    }
};