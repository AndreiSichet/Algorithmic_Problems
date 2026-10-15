/*
BIT MANIPULATION + XOR - SINGLE NUMBER

Goal:
- Find the only integer that appears once in the array.
- Every other integer appears exactly twice.
- Achieve O(n) time and O(1) extra space.

Key idea:
- Use the XOR bitwise operator (^).
- XOR has three important properties:
  1. a ^ a = 0
  2. a ^ 0 = a
  3. XOR is commutative and associative, so the order does not matter.
- XOR every element together.
- Every duplicated number cancels itself out, leaving only the single number.

Algorithm:
1. Initialize result = 0.
2. Traverse every number in nums.
3. Update result = result ^ num.
4. Return result.

Why this works:
- Every number appearing twice contributes a ^ a = 0.
- Since XOR is associative and commutative, duplicate pairs cancel
  regardless of their positions in the array.
- XOR with 0 leaves the remaining number unchanged.
- Therefore, the final result is the number that appears exactly once.

Example:
- nums = [4, 1, 2, 1, 2]
- result = 0 ^ 4 ^ 1 ^ 2 ^ 1 ^ 2
- result = 4 ^ (1 ^ 1) ^ (2 ^ 2)
- result = 4 ^ 0 ^ 0
- result = 4

Important boundaries:
- Initialize result to 0, not nums[0], so every element can be processed uniformly.
- Negative integers work correctly because XOR operates on their bit representations.
- This solution relies on every number except one appearing exactly twice.

Complexity:
- Time: O(n), because each element is processed once.
- Space: O(1), because only one variable is used.
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for (int num : nums)
            result ^= num;
        return result;
    }
};