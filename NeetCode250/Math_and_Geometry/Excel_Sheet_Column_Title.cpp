/*
BASE-26 CONVERSION - EXCEL SHEET COLUMN TITLE

Goal:
- Convert a positive integer into its Excel column title.
- Columns follow the sequence A, B, ..., Z, AA, AB, ..., AZ, BA, ...
- Unlike standard base-26, Excel columns have no zero digit.
  A represents 1, B represents 2, ..., Z represents 26.

Key idea:
- Excel column titles behave like a base-26 numbering system with digits
  from 1 to 26 instead of 0 to 25.
- Subtract 1 before taking the remainder to convert the numbering
  into a zero-based system.
- The remainder determines the current letter, and division by 26
  moves to the next position.

Algorithm:
1. Initialize an empty string result.
2. While columnNumber > 0:
   - Decrement columnNumber by 1 to handle the absence of a zero digit.
   - Calculate remainder = columnNumber % 26.
   - Convert the remainder into a letter using 'A' + remainder.
   - Append the letter to result.
   - Divide columnNumber by 26 to process the next position.
3. Reverse result because letters are generated from right to left.
4. Return result.

Why this works:
- Standard base-26 uses digits 0 through 25, but Excel uses 1 through 26.
- Subtracting 1 maps A-Z to the range 0-25.
- The remainder identifies the current letter, while integer division
  removes that digit and moves to the next position.
- Reversing the result restores the correct order of the letters.

Important boundaries:
- Always subtract 1 before calculating the remainder.
- For columnNumber = 26, the result must be Z, not BA or an invalid digit.
- For columnNumber = 27, the result must be AA.
- For multiples of 26, the decrement is essential to handle the carry
  correctly.

Complexity:
- Time: O(log_26(columnNumber)) because each iteration divides the
  number by 26.
- Space: O(log_26(columnNumber)) for the result string.
*/

class Solution {
public:
    string convertToTitle(int columnNumber) {
        string result;
        while (columnNumber > 0) {
            columnNumber--;
            int remainder = columnNumber % 26;
            result += 'A' + remainder;
            columnNumber /= 26;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};