/*
Construct Quad Tree:

Use recursion + divide and conquer.

For every square region:

1. Check if all cells have the same value.
   If yes:
       create a leaf node
       isLeaf = true
       val = grid value
       return it

2. If values are different:
       create an internal node
       isLeaf = false

       Divide the square into 4 equal parts:
           topLeft
           topRight
           bottomLeft
           bottomRight

       Recursively build all 4 parts.

       Return the current node.


Example:

    +-------+-------+
    |       |       |
    |  TL   |  TR   |
    |       |       |
    +-------+-------+
    |       |       |
    |  BL   |  BR   |
    |       |       |
    +-------+-------+

Main idea:
A region is either:
    - one leaf if all values are equal
    - 4 smaller regions if values differ


Why recursion?
Each sub-grid is exactly the same problem
as the original grid, just smaller.


Base case:
    All cells in current region are equal.


Recursive case:
    Split into 4 equal squares.


Time: O(N^2)
Every cell may be checked at each level.

Space: O(log N) recursion stack + O(number of QuadTree nodes)
*/
#include <iostream>
using namespace std;

/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {
        val = false;
        isLeaf = false;
        topLeft = nullptr;
        topRight = nullptr;
        bottomLeft = nullptr;
        bottomRight = nullptr;
    }

    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = nullptr;
        topRight = nullptr;
        bottomLeft = nullptr;
        bottomRight = nullptr;
    }

    Node(bool _val, bool _isLeaf,
         Node* _topLeft,
         Node* _topRight,
         Node* _bottomLeft,
         Node* _bottomRight) {

        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* dfs(vector<vector<int>>& grid, int r, int c, int size) {
        // Check whether this entire region
        // contains the same value.
        bool same = true;
        int value = grid[r][c];
        for (int i = r; i < r + size; i++) {
            for (int j = c; j < c + size; j++) {
                if (grid[i][j] != value) {
                    same = false;
                    break;
                }
            }
            if (!same) {
                break;
            }
        }
        // Base case:
        // Entire region has the same value.
        if (same) {
            return new Node(value, true);
        }
        // Region contains both 0 and 1.
        // Split into 4 equal parts.
        int half = size / 2;
        Node* topLeft = dfs(grid, r, c, half);
        Node* topRight = dfs(grid, r, c + half, half);
        Node* bottomLeft = dfs(grid, r + half, c, half);
        Node* bottomRight = dfs(grid, r + half, c + half, half);
        // Internal node.
        // val can be either true or false.
        return new Node( true, false, topLeft, topRight, bottomLeft, bottomRight);
    }
    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();
        return dfs(grid, 0, 0, n);
    }
};