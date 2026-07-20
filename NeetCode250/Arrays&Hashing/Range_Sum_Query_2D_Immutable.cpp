/*
2D Prefix Sum:

Precompute the sum of all rectangles from (0,0)
to every position in the matrix.

Use a prefix matrix with:
    rows + 1
    cols + 1

The extra row and column contain 0.
This makes the formula simpler and avoids boundary checks.

Formula for building prefix:

prefix[i][j] =
    matrix[i - 1][j - 1]
    + prefix[i - 1][j]
    + prefix[i][j - 1]
    - prefix[i - 1][j - 1];

Why subtract prefix[i - 1][j - 1]?
The top-left area was counted twice.

To calculate a region:

sumRegion(row1, col1, row2, col2) =
    prefix[row2 + 1][col2 + 1]
    - prefix[row1][col2 + 1]
    - prefix[row2 + 1][col1]
    + prefix[row1][col1];

We subtract the area above and the area to the left.
The top-left corner was subtracted twice,
so we add it back once.

Time Complexity:
Constructor: O(rows * cols)
sumRegion:  O(1)

Space Complexity:
O(rows * cols)

Main idea:
Precompute once so every future query is O(1).
*/

#include <iostream>
#include <vector>
using namespace std;
class NumMatrix {
private:
    vector<vector<int>> prefix;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        prefix.resize(rows + 1, vector<int>(cols + 1, 0));
        for (int i = 1; i <= rows; i++) {
            for (int j = 1; j <= cols; j++) {
                prefix[i][j] =matrix[i - 1][j - 1] + prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return prefix[row2 + 1][col2 + 1]  - prefix[row1][col2 + 1] - prefix[row2 + 1][col1] + prefix[row1][col1];
    }
};
int main() {
    vector<vector<int>> matrix = {
        {3, 0, 1, 4, 2},
        {5, 6, 3, 2, 1},
        {1, 2, 0, 1, 5},
        {4, 1, 0, 1, 7},
        {1, 0, 3, 0, 5}
    };
    NumMatrix obj(matrix);
    cout << obj.sumRegion(2, 1, 4, 3) << endl;
    cout << obj.sumRegion(1, 1, 2, 2) << endl;
    cout << obj.sumRegion(1, 2, 2, 4) << endl;
    return 0;
}