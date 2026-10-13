/*
IN-PLACE MARKERS - SET MATRIX ZEROES

Goal:
- If matrix[i][j] is 0, set every element in row i and column j to 0.
- Modify the matrix in-place.
- Achieve O(1) auxiliary space without using separate row and column arrays.

Key idea:
- Use the first row to mark which columns must become zero.
- Use the first column to mark which rows must become zero.
- matrix[i][0] == 0 means row i must become zero.
- matrix[0][j] == 0 means column j must become zero.
- The first row and first column also contain original values, so use two
  boolean flags to remember whether either one originally contained a zero.
- Mark first, then update the inner matrix, and finally handle the borders.

Algorithm:
1. Check whether the first row originally contains a zero.
   Store the result in firstRowZero.
2. Check whether the first column originally contains a zero.
   Store the result in firstColZero.
3. Traverse the inner matrix, starting from row 1 and column 1:
   - If matrix[i][j] == 0:
       Mark its row by setting matrix[i][0] = 0.
       Mark its column by setting matrix[0][j] = 0.
4. Traverse the inner matrix again:
   - If matrix[i][0] == 0 or matrix[0][j] == 0:
       Set matrix[i][j] = 0.
5. If firstRowZero is true, set every element in the first row to 0.
6. If firstColZero is true, set every element in the first column to 0.

Why this works:
- Every original zero in the inner matrix marks its corresponding row
  and column in the first column and first row.
- These markers preserve the information needed to zero the correct cells.
- The two flags preserve the original zero status of the first row and
  first column, which would otherwise be lost when using them as markers.
- Applying markers only after the marking pass prevents newly written zeros
  from being mistaken for original zeros.

Important boundaries:
- Save firstRowZero and firstColZero BEFORE modifying any cells.
- Start the marking pass at row 1 and column 1.
- Do not zero the first row or first column before processing the markers.
- The first row and first column intersect at matrix[0][0], so separate
  flags are needed to handle their original states correctly.

Complexity:
- Time: O(m * n), because the matrix is traversed a constant number of times.
- Space: O(1) auxiliary space, using only two boolean flags and the
  first row and first column as markers.
*/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        bool firstRowZero = false;
        bool firstColZero = false;
        for (int j = 0; j < n; j++) {
            if (matrix[0][j] == 0)
                firstRowZero = true;
        }
        for (int i = 0; i < m; i++) {
            if (matrix[i][0] == 0)
                firstColZero = true;
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }
        }
        if (firstRowZero) {
            for (int j = 0; j < n; j++)
                matrix[0][j] = 0;
        }
        if (firstColZero) {
            for (int i = 0; i < m; i++)
                matrix[i][0] = 0;
        }
    }
};