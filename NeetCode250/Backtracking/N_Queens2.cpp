/*
N-Queens II:

This is the same backtracking idea as N-Queens.

The difference:

    N-Queens:
        Store every valid board.

    N-Queens II:
        Only count the valid boards.

We still place one queen per row.

For every row:

    1. Try every column.
    2. Check the column.
    3. Check both diagonals.
    4. Place the queen.
    5. Recurse to the next row.
    6. Remove the queen.

We use three arrays:

    col:
        Tracks occupied columns.

    diag1:
        Tracks row - col diagonals.

    diag2:
        Tracks row + col diagonals.

When:

    row == n

we successfully placed all queens.

Instead of storing the board, simply increase
the count.

Example:

    n = 4

There are 2 valid solutions.

So:

    count = 2

You could technically solve this by generating
all boards and returning rez.size(), but that
would waste memory because N-Queens II only asks
for the number.

Time:
    O(n!)

We explore the possible queen placements.

Space:
    O(n)

The board, column array, diagonal arrays,
and recursion stack use O(n) auxiliary space.

We do not store all solutions.
*/
class Solution {
public:
    void backtrack(int row, int n, vector<string>& board, vector<bool>& col, vector<bool>& diag1, vector<bool>& diag2, int& count) {
        if (row == n) {
            count++;
            return;
        }
        for (int c = 0; c < n; c++) {
            int d1 = row - c + n;
            int d2 = row + c;
            if (col[c] || diag1[d1] || diag2[d2]) {
                continue;
            }
            // Place the queen.
            board[row][c] = 'Q';
            col[c] = true;
            diag1[d1] = true;
            diag2[d2] = true;
            backtrack(row + 1, n, board, col, diag1, diag2, count);
            // Remove the queen.
            board[row][c] = '.';
            col[c] = false;
            diag1[d1] = false;
            diag2[d2] = false;
        }
    }
    int totalNQueens(int n) {
        int count = 0;
        vector<string> board(n, string(n, '.'));
        vector<bool> col(n, false);
        vector<bool> diag1(2 * n, false);
        vector<bool> diag2(2 * n, false);
        backtrack(0, n, board, col, diag1, diag2, count);
        return count;
    }
};