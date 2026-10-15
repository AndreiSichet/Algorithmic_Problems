/*
DYNAMIC PROGRAMMING + BIT MANIPULATION - COUNTING BITS

Goal:
- For every integer i in the range [0, n], count the number of 1 bits
  in its binary representation.
- Return an array output where output[i] is the number of set bits in i.
- Solve the problem in O(n) time.

Key idea:
- Use the relationship between a number and the number obtained by
  removing its rightmost bit.
- The expression i >> 1 shifts every bit one position to the right,
  which is equivalent to integer division by 2.
- The expression i & 1 checks whether the rightmost bit is 1.
- Therefore:
  output[i] = output[i >> 1] + (i & 1).
- The value output[i >> 1] has already been calculated because i >> 1 < i.

Algorithm:
1. Create an output array of size n + 1, initialized to 0.
2. Iterate i from 1 to n.
3. Calculate output[i] = output[i / 2] + (i % 2).
   - output[i / 2] counts the 1 bits after removing the rightmost bit.
   - i % 2 contributes 1 if i is odd, otherwise 0.
4. Return output.

Why this works:
- Dividing i by 2 removes its rightmost binary bit.
- The remaining bits have the same number of 1s as i >> 1.
- If i is odd, its rightmost bit is 1, so add one.
- If i is even, its rightmost bit is 0, so add nothing.
- Since i / 2 is always smaller than i, the required result is already
  available when calculating output[i].

Important boundaries:
- output[0] = 0 because binary 0 contains no set bits.
- Even numbers have a rightmost bit of 0.
- Odd numbers have a rightmost bit of 1.
- Use previously computed results instead of counting bits from scratch.

Complexity:
- Time: O(n), because each value from 1 to n is processed once.
- Space: O(n) for the output array.
*/

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> output(n + 1, 0);
        for (int i = 1; i <= n; i++)
            output[i] = output[i / 2] + (i % 2);
        return output;
    }
};