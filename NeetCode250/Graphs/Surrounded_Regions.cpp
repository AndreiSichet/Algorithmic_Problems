/*
Surrounded Regions:

Use DFS from the borders.

The important observation:

    An O connected to the edge can never
    be surrounded.

So instead of finding surrounded regions,
find all O cells that are SAFE.

Step 1:

    Run DFS from every O on the border.

    Change every reachable O to '#'.

The '#' means:

    This O cannot be captured.

Step 2:

    Scan the entire board.

    Any remaining O is surrounded.

    Change:

        O -> X

Step 3:

    Change:

        # -> O

Now only the surrounded regions have become X.

Example:

    X X X X
    X O O X
    X O X X
    X X X X

The inner O region is not connected to the border.

After step 2:

    X X X X
    X X X X
    X X X X
    X X X X

Another example:

    X X X X
    O O X X
    X O X X
    X X X X

The O region touches the left edge.

DFS marks it:

    X X X X
    # # X X
    X # X X
    X X X X

These cells are safe.

After the final step:

    X X X X
    O O X X
    X O X X
    X X X X

Time:
    O(rows * cols)

Every cell is visited at most once by DFS
and scanned a constant number of times.

Space:
    O(rows * cols)

The recursion stack can contain every cell
in the worst case.
*/

class Solution {
public:
    int rows;
    int cols;
    void dfs(vector<vector<char>>& board, int r, int c) {
        if (r < 0 || r >= rows || c < 0 || c >= cols || board[r][c] != 'O') {
            return;
        }
        // Mark this O as safe.
        board[r][c] = '#';
        dfs(board, r - 1, c);
        dfs(board, r + 1, c);
        dfs(board, r, c - 1);
        dfs(board, r, c + 1);
    }
    void solve(vector<vector<char>>& board) {
        rows = board.size();
        cols = board[0].size();
        // Find all O cells on the border.
        for (int c = 0; c < cols; c++) {
            dfs(board, 0, c);
            dfs(board, rows - 1, c);
        }
        for (int r = 0; r < rows; r++) {
            dfs(board, r, 0);
            dfs(board, r, cols - 1);
        }
        // Capture surrounded regions.
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (board[r][c] == 'O') {
                    board[r][c] = 'X';
                }
                else if (board[r][c] == '#') {
                    board[r][c] = 'O';
                }
            }
        }
    }
};