/*
Goal:
    Given two integers a and b, calculate their sum without using
    the addition (+) or subtraction (-) operators.

Key idea:
    Use bitwise XOR and AND to simulate binary addition.

    Two operations are needed:
        1. XOR (^) calculates the sum bits without considering carries.
        2. AND (&), followed by a left shift, calculates the carry bits.

    For each pair of bits:
        0 + 0 = 0, carry 0
        0 + 1 = 1, carry 0
        1 + 0 = 1, carry 0
        1 + 1 = 0, carry 1

    XOR produces the correct result bit when there is no carry.
    AND identifies positions where both bits are 1, meaning a carry
    must be generated.
    Shifting the carry left by one moves each carry to the next position.

Algorithm:
    1. Repeat while b is not zero:
        a. Calculate the sum without carries:
               sum = a ^ b
        b. Calculate the carry bits and shift them left:
               carry = (a & b) << 1
        c. Update a to the partial sum.
        d. Update b to the carry, which must be added in the next iteration.
    2. Return a when b becomes zero.

Why this works:
    XOR calculates the sum at every bit position as if no carries existed.
    AND identifies every position where both input bits are 1.
    Shifting the AND result left moves each carry into the position
    where it needs to be added.

    Each iteration resolves the current bitwise addition and propagates
    any remaining carries.
    When b becomes zero, there are no remaining carries, so a contains
    the final sum.

Example:
    a = 5, b = 3

    Binary:
        a = 0101
        b = 0011

    Iteration 1:
        a ^ b       = 0110
        (a & b) << 1 = 0010

        a = 0110 (6)
        b = 0010 (2)

    Iteration 2:
        a ^ b       = 0100
        (a & b) << 1 = 0100

        a = 0100 (4)
        b = 0100 (4)

    Iteration 3:
        a ^ b       = 0000
        (a & b) << 1 = 1000

        a = 0000 (0)
        b = 1000 (8)

    Further iterations propagate the carry until b becomes zero.
    The final result is 1000 (8).

Important boundaries:
    - The algorithm works for positive and negative integers when
      using a fixed-width two's-complement representation.
    - In C++, signed integer overflow and left-shifting a negative
      signed value can cause undefined behavior.
    - The standard LeetCode solution assumes the platform's integer
      representation and constraints support this bitwise approach.
    - Do not use + or - to calculate the sum.
    - The loop ends only when all carry bits have been resolved.

Complexity:
    Time: O(1) for fixed-width integers, because the number of bits
          is bounded by the integer representation.
    Space: O(1), because only a constant number of variables are used.
*/

class Solution {
public:
    int getSum(int a, int b) {
        while (b != 0) {
            int sum = a ^ b;
            int carry = (a & b) << 1;
            a = sum;
            b = carry;
        }
        return a;
    }
};