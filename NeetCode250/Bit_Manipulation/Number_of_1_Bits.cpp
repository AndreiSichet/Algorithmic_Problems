/*
BIT MANIPULATION - NUMBER OF 1 BITS

Goal:
- Count the number of set bits (bits equal to 1) in an unsigned integer.
- Return the total number of 1s in its 32-bit binary representation.

Key idea:
- Use Brian Kernighan's algorithm to remove one set bit per iteration.
- The operation n & (n - 1) turns the rightmost 1 bit into 0.
- Repeat until n becomes 0.
- The number of iterations equals the number of set bits.

Algorithm:
1. Initialize count = 0.
2. While n != 0:
   - Update n = n & (n - 1) to remove the rightmost set bit.
   - Increment count.
3. Return count.

Why this works:
- Subtracting 1 flips the rightmost 1 bit to 0 and changes the trailing
  zeros into ones.
- ANDing the original number with n - 1 clears exactly that rightmost 1 bit.
- Every iteration removes one set bit without changing the other set bits.
- When n becomes 0, all original set bits have been counted.

Example:
- n = 13, binary = 1101
- 1101 & 1100 = 1100, count = 1
- 1100 & 1011 = 1000, count = 2
- 1000 & 0111 = 0000, count = 3
- Return 3.

Important boundaries:
- If n = 0, the loop never executes and the answer is 0.
- The method works for all 32-bit unsigned integers.
- Unlike checking all 32 bit positions, this algorithm only iterates
  as many times as there are set bits.

Complexity:
- Time: O(k), where k is the number of set bits; worst case O(1) for
  a fixed 32-bit integer.
- Space: O(1), because only a counter is used.
*/

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while (n != 0) {
            n &= (n - 1);
            count++;
        }
        return count;
    }
};