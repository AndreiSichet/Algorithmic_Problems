/*
Combination Sum:

Use BACKTRACKING.

For every number, we have two choices:

    1. Choose nums[index]
       - Add it to the combination.
       - Stay at the same index.
       - This allows unlimited reuse.

    2. Skip nums[index]
       - Remove it from the combination.
       - Move to index + 1.

Example:

    nums = [2, 3, 6, 7]
    target = 7

                         []
                       /    \
                    choose 2  skip 2
                      [2]       []
                     /   \       \
                  choose 2  skip 2
                    [2,2]     [2]
                       ...
                       |
                    [2,2,3]
                       |
                    target = 0
                       |
                    add result

The important part is:

    Choose:
        backtrack(index, target - nums[index])

    Skip:
        backtrack(index + 1, target)

Why does choosing stay at the same index?

Because we can use the same number unlimited times.

Why do we move forward when skipping?

This prevents duplicate combinations.

For example, these should NOT both appear:

    [2,3,2]
    [2,2,3]

They contain the same numbers with the same frequencies.

By only moving forward through nums, we generate:

    [2,2,3]

but never generate the same combination in another order.

Base cases:

    target == 0:
        We found a valid combination.

    target < 0:
        The current combination is too large.

    index >= nums.size():
        No numbers are left to try.

Example:

    nums = [2,3,6,7]
    target = 7

    [2,2,3] = 7
    [7]     = 7

Time:
    O(2^target) approximately

The exact complexity depends on the values in nums.

Space:
    O(target)

The recursion depth depends on how many times
the smallest number can be chosen.

The result itself requires additional space.
*/

class Solution {
public:
    void backtrack(vector<int>& nums, int index, int target, vector<int>& combination, vector<vector<int>>& result) {
        if (target == 0) {
            result.push_back(combination);
            return;
        }
        if (target < 0 || index >= nums.size()) {
            return;
        }
        // Choose the current number and allow reuse.
        combination.push_back(nums[index]);
        backtrack(nums, index, target - nums[index], combination, result);
        // Skip the current number and move forward.
        combination.pop_back();
        backtrack(nums, index + 1, target, combination, result);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        vector<int> combination;
        backtrack(nums, 0, target, combination, result);
        return result;
    }
};