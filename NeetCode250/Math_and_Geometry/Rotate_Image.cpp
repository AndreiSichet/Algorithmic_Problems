/*
TRANSPOSE + REVERSE ROWS - ROTATE IMAGE

Goal:
- Rotate an n x n matrix 90 degrees clockwise.
- Modify the matrix in-place without allocating another 2D matrix.

Key idea:
- A 90-degree clockwise rotation can be performed in two operations:
  1. Transpose the matrix by swapping rows and columns.
  2. Reverse every row.
- Transposition moves matrix[i][j] to matrix[j][i].
- Reversing each row moves the elements into their final clockwise positions.

Algorithm:
1. Get the matrix dimension n.
2. Transpose the matrix:
   - Iterate through rows i.
   - Iterate through columns j starting at i + 1.
   - Swap matrix[i][j] with matrix[j][i].
   - Starting at i + 1 prevents swapping the same pair twice.
3. Reverse every row using reverse(matrix[i].begin(), matrix[i].end()).
4. Return nothing because the matrix is modified in-place.

Why this works:
- After transposition, columns become rows and rows become columns.
- Reversing each row changes the orientation from a reflection across
  the main diagonal to a 90-degree clockwise rotation.
- Every element reaches its required final position without creating
  another matrix.

Important boundaries:
- Transpose only the elements above the main diagonal.
- Do not transpose the entire matrix by swapping every pair, because
  that would swap each pair twice and undo the operation.
- Reverse rows, not columns, for a clockwise rotation.
- The matrix must be square for this in-place approach.

Complexity:
- Time: O(n^2), because the matrix elements are processed a constant
  number of times.
- Space: O(1) auxiliary space, because the rotation is performed in-place.
*/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for (int i = 0; i < n; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};