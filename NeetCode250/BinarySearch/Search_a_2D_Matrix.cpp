/*
Search a 2D Matrix:

Treat the matrix as one
sorted array.

There is no need to flatten it.

Binary search over the range:

0 ... (m*n - 1)

For each middle index:

    row = mid / number_of_columns

    col = mid % number_of_columns

Compare matrix[row][col]
with the target.

If smaller:
    Search the right half.

If larger:
    Search the left half.

If equal:
    Return true.

If the search ends,
the target is not present.

Main insight:

Because every row starts
with a value greater than
the previous row's last value,
the entire matrix behaves
like one sorted array.

Use index mapping instead
of creating a new array.

Important details:

row = mid / cols

col = mid % cols

Time Complexity:

O(log(m*n))

Space Complexity:

O(1)
*/
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int left = 0;
        int right = m * n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int row = mid / n;
            int col = mid % n;
            if (matrix[row][col] == target)
                return true;
            if (matrix[row][col] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return false;
    }
};
int main() {
    Solution sol;
    vector<vector<int>> matrix = {
        {1,2,4,8},
        {10,11,12,13},
        {14,20,30,40}
    };
    cout << sol.searchMatrix(matrix, 10) << endl;
    cout << sol.searchMatrix(matrix, 15) << endl;
    return 0;
}