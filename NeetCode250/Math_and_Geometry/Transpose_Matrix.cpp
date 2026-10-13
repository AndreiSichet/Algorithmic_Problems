/*
MATRIX TRAVERSAL - TRANSPOSE MATRIX

Goal:
- Return the transpose of a given matrix.
- The transpose swaps every element's row and column indices.
- An element at matrix[i][j] moves to result[j][i].

Key idea:
- If the original matrix has m rows and n columns, its transpose has
  n rows and m columns.
- Create a new matrix with the dimensions reversed.
- Copy each element from its original position to the swapped position.

Algorithm:
1. Get the number of rows m and columns n.
2. Create a result matrix with n rows and m columns.
3. Traverse every element matrix[i][j].
4. Assign matrix[i][j] to result[j][i].
5. Return result.

Why this works:
- Transposition exchanges the row and column indices of every element.
- Assigning result[j][i] = matrix[i][j] performs exactly this operation.
- Reversing the dimensions ensures every element fits in the result matrix,
  including when the original matrix is not square.

Important boundaries:
- Do not assume the matrix is square.
- For an m x n matrix, the result must be n x m.
- A square matrix keeps the same dimensions, but its elements are still
  reflected across the main diagonal.
- Each original element is copied exactly once.

Complexity:
- Time: O(m * n), because every element is visited once.
- Space: O(m * n) for the transposed matrix.
*/

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<vector<int>> result(cols, vector<int>(rows));
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result[j][i] = matrix[i][j];
            }
        }
        return result;
    }
};