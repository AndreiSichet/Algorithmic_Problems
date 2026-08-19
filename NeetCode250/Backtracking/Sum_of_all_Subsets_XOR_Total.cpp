/*
Sum of All Subsets XOR Total:

Use the fact that every bit can be considered independently.

For each bit:

    If ANY number in nums has this bit set:
        that bit will appear in the XOR total
        for exactly half of all subsets.

Why?

For a particular bit, each element either:
    has the bit -> contributes 1
    does not have the bit -> contributes 0

Across all subsets, the number of subsets where the XOR bit is 1 is exactly half.

There are:

    2^n total subsets

So if a bit can appear at all, it contributes:

    2^(n - 1) * bit_value

We can find all bits that appear in at least one number using OR:

    OR = nums[0] | nums[1] | ... | nums[n-1]

Every bit that exists in OR will contribute.

Therefore:

    answer = OR * 2^(n - 1)

Example:

    nums = [2, 5, 6]

    2 = 010
    5 = 101
    6 = 110

    OR = 111 = 7

There are 3 elements:

    2^(3 - 1) = 4

Answer:

    7 * 4 = 28

Why OR?

OR tells us which bits appear in at least one number.
Every such bit appears in the XOR of exactly half
of all subsets.

Time:
    O(n)

Space:
    O(1)
*/

class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int bits = 0;
        for (int num : nums) {
            bits |= num;
        }
        return bits * (1 << (nums.size() - 1));
    }
};