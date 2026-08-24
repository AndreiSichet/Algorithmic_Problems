/*
Word Search II:

Use a TRIE + BACKTRACKING.

The problem gives us many words.

Searching for every word separately would repeat
work because different words can share prefixes.

Example:

    words = ["oat", "oath"]

Both words share:

    o -> a -> t

A Trie stores this shared prefix only once.

Then we perform DFS from every board cell.

During DFS, we move through:

    1. The board.
    2. The Trie.

For every board cell:

    If the character does not exist as a child
    of the current Trie node, stop this path.

    Otherwise move to that Trie child.

If the Trie node contains a complete word,
we found a word.

Each board cell can only be used once in the
current path.

So when we visit a cell:

    1. Save its character.
    2. Mark it as visited.
    3. Explore its four neighbors.
    4. Restore the character.

The four directions are:

    up
    down
    left
    right

We store the complete word in the Trie node.

This means that when we reach that node,
we do not need to construct the word again.

After finding a word, we set:

    curr->word = ""

This prevents adding the same word multiple times.

We also remove the Trie node when it becomes
empty after DFS.

This is an optimization that prevents us from
searching a prefix that cannot lead to another word.

Example:

    If "oath" is the only word below a Trie path
    and we already found "oath", that path is no
    longer useful.

Time:
    Depends on the board size and the words.

The Trie greatly reduces repeated prefix searches.

A common upper bound is approximately:

    O(m * n * 4^L)

where:

    m = number of board cells
    n = number of words
    L = maximum word length

In practice, the Trie and pruning make this much
faster than searching for every word independently.

Space:

    O(total characters in all words)

for the Trie, plus O(L) recursion depth.

*/

class Solution {
private:
    struct Node {
        Node* children[26];
        string word;
        Node() {
            word = "";
            for (int i = 0; i < 26; i++) {
                children[i] = nullptr;
            }
        }
    };
    int rows;
    int cols;
    void backtrack(vector<vector<char>>& board, int r, int c, Node* curr, vector<string>& rez) {
        if (board[r][c] == '#') {
            return;
        }
        char ch = board[r][c];
        int index = ch - 'a';
        if (curr->children[index] == nullptr) {
            return;
        }
        curr = curr->children[index];
        // Found a complete word.
        if (!curr->word.empty()) {
            rez.push_back(curr->word);
            curr->word = "";
        }
        board[r][c] = '#';
        if (r > 0) {
            backtrack(board, r - 1, c, curr, rez);
        }
        if (r + 1 < rows) {
            backtrack(board, r + 1, c, curr, rez);
        }
        if (c > 0) {
            backtrack(board, r, c - 1, curr, rez);
        }
        if (c + 1 < cols) {
            backtrack(board, r, c + 1, curr, rez);
        }
        // Restore the cell.
        board[r][c] = ch;
    }
    void insert(Node* root, string& word) {
        Node* curr = root;
        for (char c : word) {
            int index = c - 'a';
            if (curr->children[index] == nullptr) {
                curr->children[index] = new Node();
            }
            curr = curr->children[index];
        }
        curr->word = word;
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        rows = board.size();
        cols = board[0].size();
        Node* root = new Node();
        for (string& word : words) {
            insert(root, word);
        }
        vector<string> rez;
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                backtrack(board, r, c, root, rez);
            }
        }
        return rez;
    }
};