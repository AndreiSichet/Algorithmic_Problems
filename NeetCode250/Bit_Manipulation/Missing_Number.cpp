/*
Goal:
    Given an array nums containing n distinct integers in the range [0, n],
    find the single number in that range that is missing from the array.

Key idea:
    Use the XOR operation to find the missing number in O(n) time
    and O(1) extra space.

    XOR has two important properties:
        1. a ^ a = 0
           XORing a number with itself cancels it out.
        2. a ^ 0 = a
           XORing a number with zero leaves it unchanged.

    XOR is also commutative and associative, meaning the order of
    XOR operations does not affect the final result.

    If we XOR every number from 0 to n and every element in nums,
    all numbers that appear in both groups cancel out.
    Only the missing number remains.

Algorithm:
    1. Initialize result = n.
       This includes the last number in the complete range [0, n].
    2. Iterate through every index i from 0 to n - 1:
        a. XOR result with i.
        b. XOR result with nums[i].
    3. Return result.

Why this works:
    The complete range [0, n] contains every possible number,
    including the missing number.

    Every array element belongs to this range, and every number
    except the missing one appears exactly once in nums.

    Therefore, XORing all indices and array elements cancels out
    every number that appears in both groups.

    The initial result = n accounts for the range's last number,
    which is not an array index.

    After all cancellations, result contains only the missing number.

Example:
    nums = [3, 0, 1]
    n = 3

    Complete range: 0, 1, 2, 3
    Array elements: 3, 0, 1

    result = 3
    result ^= 0 ^ 3
    result ^= 1 ^ 0
    result ^= 2 ^ 1

    All matching numbers cancel out:
        0 ^ 0 = 0
        1 ^ 1 = 0
        3 ^ 3 = 0

    The remaining value is 2, which is the missing number.

Important boundaries:
    - The array can contain 0 as a valid element.
    - The missing number can be n, the largest number in the range.
    - The array can be empty. In that case, n = 0 and the answer is 0.
    - No sorting or additional data structures are needed.
    - XOR avoids the potential integer overflow of the sum-based
      approach when calculating n * (n + 1) / 2 for large inputs.

Complexity:
    Time: O(n), because each array element is processed once.
    Space: O(1), because only a constant number of variables are used.
*/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int result = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            result ^= i;
            result ^= nums[i];
        }
        return result;
    }
};