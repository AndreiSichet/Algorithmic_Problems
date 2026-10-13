/*
BOUNDARY SIMULATION - SPIRAL MATRIX

Goal:
- Return all matrix elements in clockwise spiral order.
- Start at the top-left corner and move right, then down, left, and up.
- Continue inward until every element has been visited exactly once.

Key idea:
- Maintain four boundaries that define the unvisited portion of the matrix:
  top, bottom, left, and right.
- Traverse one boundary at a time in clockwise order.
- After finishing a boundary, move it inward.
- Continue while the boundaries have not crossed.

Algorithm:
1. Initialize:
   - top = 0
   - bottom = m - 1
   - left = 0
   - right = n - 1
2. While top <= bottom and left <= right:
   - Traverse the top row from left to right.
     Then increment top.
   - Traverse the right column from top to bottom.
     Then decrement right.
   - If top <= bottom:
       Traverse the bottom row from right to left.
       Then decrement bottom.
   - If left <= right:
       Traverse the left column from bottom to top.
       Then increment left.
3. Return the result.

Why this works:
- The four boundaries enclose all elements that have not been visited.
- Each traversal processes one outer edge of the remaining matrix.
- Moving the corresponding boundary inward prevents revisiting elements.
- The conditions before traversing the bottom row and left column prevent
  duplicate visits when only one row or one column remains.
- The loop ends when every row or column boundary has crossed.

Important boundaries:
- Use top <= bottom and left <= right in the main loop.
- Check top <= bottom before traversing the bottom row.
- Check left <= right before traversing the left column.
- These checks are essential for matrices with a single row or column.
- The algorithm works for rectangular matrices, not just square matrices.

Complexity:
- Time: O(m * n), because every element is visited exactly once.
- Space: O(1) auxiliary space, excluding the O(m * n) output array.
*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int top = 0;
        int bottom = m - 1;
        int left = 0;
        int right = n - 1;
        vector<int> result;
        result.reserve(m * n);
        while (top <= bottom && left <= right) {
            for (int col = left; col <= right; col++)
                result.push_back(matrix[top][col]);
            top++;
            for (int row = top; row <= bottom; row++)
                result.push_back(matrix[row][right]);
            right--;
            if (top <= bottom) {
                for (int col = right; col >= left; col--)
                    result.push_back(matrix[bottom][col]);
                bottom--;
            }
            if (left <= right) {
                for (int row = bottom; row >= top; row--)
                    result.push_back(matrix[row][left]);
                left++;
            }
        }
        return result;
    }
};