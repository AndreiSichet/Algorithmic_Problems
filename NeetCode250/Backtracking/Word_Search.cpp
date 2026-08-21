/*
Word Search:

Use BACKTRACKING with DFS.

We need to find a path that matches the word.

From every cell, we try to start the word.

For each matching cell, we can move in four directions:

              up
               |
        left - cell - right
               |
             down

We cannot move diagonally.

At each cell:

    1. Check if the position is valid.
    2. Check if board[r][c] matches word[index].
    3. Mark the cell as visited.
    4. Search in all four directions.
    5. Restore the cell when backtracking.

Why do we restore the cell?

A cell cannot be used twice in the SAME path,
but it can be used again in a DIFFERENT path.

Example:

    A B
    C D

If we use A in one path, we temporarily mark A
as visited.

After that path fails, we restore A so another
possible path can use it.

We can mark a cell as visited by changing it
temporarily:

    board[r][c] = '#'

Then restore it:

    board[r][c] = word[index]

Base case:

    index == word.size()

This means every character has been matched,
so the word exists in the board.

Important:

    We return true immediately when one valid path
    is found.

Example:

    board:

        A B C
        D E F
        G H I

    word = "ABE"

    Start at A:

        A -> B
             |
             E

    The word exists.

Time:
    O(m * n * 4 * 3^(L - 1))

m = number of rows
n = number of columns
L = length of word

We try every cell as a starting position.
After the first move, we have at most 3 choices
because we cannot immediately reuse the previous cell.

Space:
    O(L)

The recursion depth is at most the length of the word.
*/

class Solution {
public:
    bool backtrack(vector<vector<char>>& board,string& word,int r, int c,int index) {
        if (index == word.size()) {
            return true;
        }
        if (r < 0 || r >= board.size() || c < 0 || c >= board[0].size() || board[r][c] != word[index]) {
            return false;
        }
        char temp = board[r][c];
        board[r][c] = '#';
        bool found =backtrack(board, word, r + 1, c, index + 1) || 
            backtrack(board, word, r - 1, c, index + 1) || 
            backtrack(board, word, r, c + 1, index + 1) ||
            backtrack(board, word, r, c - 1, index + 1);
        board[r][c] = temp;
        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for (int r = 0; r < board.size(); r++) {
            for (int c = 0; c < board[0].size(); c++) {
                if (backtrack(board, word, r, c, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
};