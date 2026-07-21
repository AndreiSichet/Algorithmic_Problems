/*
Valid Sudoku:

Check for duplicates in:

1. Every row
2. Every column
3. Every 3x3 box

Use an unordered_map to count the frequency
of each digit.

For every non-empty cell:

	freq[board[i][j]]++;

	if (freq[board[i][j]] > 1)
		return false;


For the 3x3 boxes:

Start positions are:

	(0,0), (0,3), (0,6)
	(3,0), (3,3), (3,6)
	(6,0), (6,3), (6,6)

Use:

	row += 3
	col += 3

and check the 3x3 area from that position.


Important:
	'.' means empty cell.
	board[i][j] is a char, so use '.' not ".".
	No need for stoi().

Time Complexity:O(1)
Space Complexity:O(1)
The board is always 9 x 9,
so the input size is fixed.
Main idea:
Check rows, columns, and 3x3 boxes
for duplicate digits.
*/
#include<iostream>
#include<vector>
#include<unordered_map>
class Solution {
public:
	bool isValidSudoku(vector<vector<char>>& board) {
		//Check rows
		for (int i = 0; i < 9; i++) {
			unordered_map<char, int>freq1;
			for (int j = 0; j < 9; j++) {
				if (board[i][j] == '.') continue;
				freq1[board[i][j]++;
				if (freq1[board[i][j]] > 1) return false;
			}
		}
		//Check columns
		for (int j = 0; j < 9; j++) {
			unordered_map<char, int>freq2;
			for (int i = 0; i < 9; i++) {
				if (board[i][j] == '.') continue;
				freq2[board[i][j]]++;
				if (freq2[board[i][j]] > 1) return false;
			}
		}
		// Check 3x3 boxes
		for (int row = 0; row < 9; row += 3) {
			for (int col = 0; col < 9; col += 3) {
				unordered_map<char, int> freq;
				for (int i = row; i < row + 3; i++) {
					for (int j = col; j < col + 3; j++) {
						if (board[i][j] == '.') continue;
						freq[board[i][j]]++;
						if (freq[board[i][j]] > 1) {
							return false;
						}
					}
				}
			}
		}
		return true;

	}
};