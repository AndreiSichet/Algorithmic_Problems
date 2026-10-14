/*
ARRAY TRAVERSAL + CARRY - PLUS ONE

Goal:
- Increment the integer represented by an array of digits by one.
- Return the resulting digits without converting the array into an integer.
- Handle arbitrarily large numbers that may exceed standard integer limits.

Key idea:
- Start from the least significant digit, at the end of the array.
- If a digit is less than 9, increment it and return immediately.
- If a digit is 9, it becomes 0 and the carry continues to the left.
- If every digit is 9, prepend a 1 to the array.

Algorithm:
1. Traverse digits from right to left.
2. For each digit:
   - If digits[i] < 9:
       Increment digits[i].
       Return digits immediately because no further carry is needed.
   - Otherwise:
       Set digits[i] = 0 because 9 + 1 produces 0 with a carry.
3. If the loop finishes, every digit was 9.
   Insert 1 at the beginning of the array.
4. Return digits.

Why this works:
- Adding one affects only the trailing sequence of 9s and the first
  digit to their left that is less than 9.
- Digits smaller than 9 can be incremented without producing a carry.
- Each trailing 9 becomes 0 while passing the carry to the left.
- If every digit is 9, the result requires one additional digit.

Important boundaries:
- [1, 2, 3] becomes [1, 2, 4].
- [1, 2, 9] becomes [1, 3, 0].
- [9, 9, 9] becomes [1, 0, 0, 0].
- Do not convert the array to an integer because the number may be too large.
- Return immediately after incrementing a digit smaller than 9.

Complexity:
- Time: O(n) in the worst case when all digits are 9.
- Space: O(1) auxiliary space, excluding any reallocation needed by the vector.
*/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for (int i = digits.size() - 1; i >= 0; i--) {
            if (digits[i] < 9) {
                digits[i]++;
                return digits;
            }
            digits[i] = 0;
        }
        digits.insert(digits.begin(), 1);
        return digits;
    }
};