/*
N-Queens:

Use BACKTRACKING.

We place one queen in each row.

For every row, try every column.

Example for n = 4:

    row 0:
        try column 0
        try column 1
        try column 2
        try column 3

    After choosing a column for row 0,
    move to row 1 and repeat.

Because we place exactly one queen per row,
queens can never attack each other horizontally.

We only need to check:

    1. Column
    2. Main diagonal
    3. Other diagonal

We use three arrays to track them.

Column:

    col[c]

Main diagonal:

    row - col

Other diagonal:

    row + col

For the main diagonal, row - col can be negative, so we use:

    row - col + n - 1

Example:

    Queen at (0,2):

        row - col = -2
        index = -2 + n - 1

    Queen at (2,0):

        row - col = 2

If two queens have the same row - col, they are on the same main diagonal.

If two queens have the same row + col, they are on the same other diagonal.

Backtracking:

    1. Try a column in the current row.
    2. Check if the position is safe.
    3. Mark the column and diagonals.
    4. Place the queen.
    5. Move to the next row.
    6. Remove the queen.
    7. Unmark the column and diagonals.

Visual:

                    row 0
             /        |        \
           col 0    col 1     col 2
             |        |         |
          row 1     row 1      row 1
          / | \     / | \      / | \
         ...       ...        ...

We continue until all n rows contain
a queen.

Base case:

    row == n

All queens have been placed, so we add the board to the result.

Example for n = 4:

    . Q . .
    . . . Q
    Q . . .
    . . Q .

This is one valid solution.

Time:
    O(n!)

There are n choices for the first row,
at most n - 1 for the second, and so on.

The safety checks are O(1).

Space:
    O(n^2)

The board itself uses O(n^2).
The column and diagonal arrays use O(n).
The recursion uses O(n).

The result itself requires additional space.
*/

class Solution {
public:
    void backtrack(int row, int n, vector<string>& board, vector<bool>& col, vector<bool>& diag1, vector<bool>& diag2, vector<vector<string>>& rez) {
        if (row == n) {
            rez.push_back(board);
            return;
        }
        for (int c = 0; c < n; c++) {
            int d1 = row - c + n - 1;
            int d2 = row + c;
            if (col[c] || diag1[d1] || diag2[d2]) {
                continue;
            }
            // Place the queen.
            board[row][c] = 'Q';
            col[c] = true;
            diag1[d1] = true;
            diag2[d2] = true;
            backtrack(row + 1, n, board, col, diag1, diag2, rez);
            // Remove the queen.
            board[row][c] = '.';
            col[c] = false;
            diag1[d1] = false;
            diag2[d2] = false;
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> rez;
        vector<string> board(n, string(n, '.'));
        vector<bool> col(n, false);
        vector<bool> diag1(2 * n - 1, false);
        vector<bool> diag2(2 * n - 1, false);
        backtrack(0, n, board, col, diag1, diag2, rez);
        return rez;
    }
};