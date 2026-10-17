/*
Goal:
    Given a signed 32-bit integer x, reverse its decimal digits and
    return the reversed integer.

    If the reversed number falls outside the signed 32-bit integer range:
        [-2147483648, 2147483647]
    return 0.

Key idea:
    Extract the last digit of x using the modulo operator (%),
    then append that digit to the reversed number.

    In each iteration:
        1. Extract the last digit: digit = x % 10.
        2. Remove the last digit from x: x /= 10.
        3. Append the extracted digit to the result:
               result = result * 10 + digit.

    Before appending a digit, check whether multiplying result by 10
    and adding digit would cause a 32-bit signed integer overflow.

Algorithm:
    1. Initialize result = 0.
    2. While x is not zero:
        a. Extract the last digit using x % 10.
        b. Remove the last digit using x /= 10.
        c. Check whether result * 10 + digit would exceed the
           signed 32-bit integer boundaries.
        d. If overflow would occur, return 0.
        e. Otherwise, append the digit to result.
    3. Return result.

Why this works:
    Every iteration removes one digit from x and appends it to result.
    Multiplying result by 10 shifts its existing digits one position
    to the left, creating space for the extracted digit.

    For example, reversing 123:
        result = 0 * 10 + 3 = 3
        result = 3 * 10 + 2 = 32
        result = 32 * 10 + 1 = 321

    Negative numbers work because C++ preserves the sign when applying
    the remainder and division operators to integers.
    For example, -123 produces the digits -3, -2, and -1, resulting
    in -321.

    The overflow check must happen BEFORE calculating result * 10 + digit.
    Otherwise, the calculation itself could exceed the integer range.

Important boundaries:
    - INT_MAX = 2147483647.
    - INT_MIN = -2147483648.
    - If result > INT_MAX / 10, multiplying it by 10 will overflow.
    - If result == INT_MAX / 10, a positive digit greater than 7
      would exceed INT_MAX.
    - If result < INT_MIN / 10, multiplying it by 10 will overflow.
    - If result == INT_MIN / 10, a negative digit less than -8
      would fall below INT_MIN.
    - Leading zeros disappear naturally. For example, 120 becomes 21.
    - A negative sign stays with the reversed number. For example,
      -120 becomes -21.
    - No wider integer type is needed.

Complexity:
    Time: O(log10(|x|)), because each iteration processes one decimal digit.
          Since a 32-bit integer has at most 10 decimal digits, this is O(1).
    Space: O(1), because only a constant number of variables are used.
*/

class Solution {
public:
    int reverse(int x) {
        int result = 0;
        while (x != 0) {
            int digit = x % 10;
            x /= 10;
            if (result > INT_MAX / 10 || (result == INT_MAX / 10 && digit > 7)) {
                return 0;
            }
            if (result < INT_MIN / 10 || (result == INT_MIN / 10 && digit < -8)) {
                return 0;
            }
            result = result * 10 + digit;
        }
        return result;
    }
};