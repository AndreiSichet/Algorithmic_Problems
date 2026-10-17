/*
Goal:
    Given two integers n and x, construct a strictly increasing array
    of n positive integers such that the bitwise AND of all elements
    equals x.

    Return the minimum possible value of the last element nums[n - 1].

Key idea:
    Every element must contain all the set bits of x.
    Otherwise, the bitwise AND of all elements would lose at least one
    set bit that must remain in the final result.

    Therefore, every element must satisfy:
        (nums[i] & x) == x

    The minimum possible last element can be found by starting with x
    and placing the binary representation of n - 1 into the zero-bit
    positions of x, from least significant to most significant.

    Why n - 1?
        The first element can be x itself.
        Each subsequent element needs a distinct combination of bits
        in positions where x has zeros.
        There are n elements, so we need n distinct combinations,
        indexed from 0 to n - 1.

    Important:
        Bits that are already 1 in x must never change.
        We only use zero-bit positions to encode n - 1.

Algorithm:
    1. Initialize result = x.
    2. Initialize bit = 1, representing the current bit position.
    3. Initialize remaining = n - 1, the number to encode into
       the zero-bit positions of x.
    4. While remaining is greater than zero:
        a. If the current bit position is zero in x:
            - If the least significant bit of remaining is 1,
              set this bit in result.
            - Shift remaining right by one bit.
        b. Shift bit left to examine the next position.
    5. Return result.

Why this works:
    The smallest valid sequence starts at x and increases by changing
    only bit positions where x contains zero.

    Consider:
        n = 3
        x = 4

    Binary representation of x:
        100

    We need three distinct combinations of the available zero-bit
    positions, indexed by 0, 1, and 2.

        Index 0: 100 = 4
        Index 1: 101 = 5
        Index 2: 110 = 6

    The resulting array is:
        [4, 5, 6]

    Check the AND:
        100
        101
        110
        ---
        100 = 4

    The array is strictly increasing, its bitwise AND equals x,
    and the last element is as small as possible.

    Encoding n - 1 into the zero-bit positions of x gives the
    minimum last element because it uses the lowest available
    bit positions first, without changing any set bit of x.

Important boundaries:
    - If n == 1, the array contains only x, so the answer is x.
    - x is positive, so it already satisfies the positive-integer
      requirement.
    - Do not simply return x + n - 1. Some bits in those consecutive
      numbers may be zero where x has a set bit, violating the AND
      requirement.
    - Use a 64-bit integer because the answer can exceed the range
      of a signed 32-bit integer.
    - Use 1LL for bit operations to avoid shifting a 32-bit integer
      beyond its supported width.

Complexity:
    Time: O(log(n) + log(answer)), because we examine bit positions
          until all bits of n - 1 have been encoded.
    Space: O(1), because only a constant number of variables are used.
*/

class Solution {
public:
    long long minEnd(int n, int x) {
        long long result = x;
        long long remaining = n- 1;
        long long bit = 1;
        while (remaining > 0) {
            if ((result & bit) == 0) {
                if (remaining & 1) {
                    result |= bit;
                }
                remaining >>= 1;
            }
            bit <<= 1;
        }
        return result;
    }
};