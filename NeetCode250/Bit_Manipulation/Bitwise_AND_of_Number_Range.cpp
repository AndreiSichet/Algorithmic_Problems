/*
Goal:
    Given two integers left and right representing the inclusive range
    [left, right], calculate the bitwise AND of every integer in that range.

Key idea:
    Find the common binary prefix shared by left and right.

    When performing bitwise AND across every number in a continuous range,
    any bit position that changes between 0 and 1 becomes 0 in the final
    result.

    Only the common leading bits shared by left and right can remain 1.

    The right-shift operator (>>) removes the rightmost bit.
    By repeatedly shifting both numbers right until they become equal,
    we identify their common binary prefix.

    After finding the common prefix, shift it back to its original
    position using the left-shift operator (<<).

Algorithm:
    1. Initialize shift = 0 to count how many bit positions are removed.
    2. While left and right are different:
        a. Shift left one position to the right.
        b. Shift right one position to the right.
        c. Increment shift.
    3. Once left == right, their remaining bits represent the common prefix.
    4. Shift the common prefix left by shift positions.
    5. Return the result.

Why this works:
    Consider the range [5, 7]:

        5 = 101
        6 = 110
        7 = 111

    Bitwise AND:
        101
        110
        111
        ---
        100 = 4

    The rightmost two bits are not common across all numbers.
    Only the leading bit remains unchanged.

    Shifting both endpoints right:
        101 >> 1 = 10
        111 >> 1 = 11

        10 >> 1 = 1
        11 >> 1 = 1

    The common prefix is 1, and we shifted twice.
    Shifting it back gives:
        1 << 2 = 100 = 4

    Therefore, the result is 4.

Important boundaries:
    - If left == right, the range contains one number, so return that number.
    - If left == 0, the result is always 0 because 0 AND any number is 0.
    - The range is inclusive, so both endpoints must be considered.
    - Do not iterate through every number in the range. The range can be
      extremely large, making that approach inefficient.
    - The loop stops when both endpoints share the same remaining prefix.
    - The number of iterations is bounded by the number of bits in an integer.

Complexity:
    Time: O(log(right)), because each iteration shifts the endpoints
          one bit to the right.
    Space: O(1), because only one additional variable is used.
*/

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int shift = 0;
        while (left != right) {
            left >>= 1;
            right >>= 1;
            shift++;
        }
        return left << shift;
    }
};