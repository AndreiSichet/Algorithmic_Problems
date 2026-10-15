/*
Goal:
    Reverse the order of all 32 bits of an unsigned integer n.
    The least significant bit becomes the most significant bit,
    and the most significant bit becomes the least significant bit.

Key idea:
    Build the reversed number one bit at a time.
    In each iteration:
        1. Shift the result left by one position to make room for a bit.
        2. Extract the least significant bit of n using n & 1.
        3. Add that bit to the result using bitwise OR.
        4. Shift n right to process its next bit.

Algorithm:
    1. Initialize result = 0.
    2. Repeat exactly 32 times:
        a. Shift result left by one bit.
        b. Add the last bit of n to result using result |= (n & 1).
        c. Shift n right by one bit.
    3. Return result.

Why this works:
    The expression n & 1 extracts the rightmost bit of n.
    Shifting result left creates an empty rightmost position.
    Adding the extracted bit appends it to the reversed number.
    Repeating this process 32 times processes every bit, including
    leading zeros in the original binary representation.

Important boundaries:
    - Always perform exactly 32 iterations because the input is
      represented using 32 bits.
    - Leading zeros must be processed too. For example, reversing
      00000000...0001 produces 10000000...0000.
    - Use unsigned int so right shifts behave as logical shifts
      for the 32-bit unsigned input.

Complexity:
    Time: O(1), because exactly 32 iterations are performed.
    Space: O(1), because only a constant number of variables are used.
*/

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        for (int i = 0; i < 32; i++) {
            result <<= 1;
            result |= (n & 1);
            n >>= 1;
        }
        return result;
    }
};