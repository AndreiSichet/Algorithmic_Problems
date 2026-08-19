/*
Subsets:

For every number, we have TWO choices:

    1. Include nums[index]
    2. Don't include nums[index]

This creates a decision tree.

Example:

    nums = [1, 2]

                    []
                  /    \
              include   don't include
                1            1
               [1]           []
              /   \         /   \
             2     -       2     -
           [1,2]  [1]     [2]    []

Every time we reach:

    index == nums.size()

we have made a decision for every number.

Therefore, the current subset is complete, so we add it to the result.

Backtracking:

    subset.push_back(nums[index]);

    Explore the choice where we INCLUDE the number.

    subset.pop_back();

    Explore the choice where we DON'T INCLUDE the number.

The pop_back() is important because we need to restore the subset before exploring the second choice.

For n numbers:

    2 choices for every number
    => 2^n subsets

Time:
    O(n * 2^n)

There are 2^n subsets and copying each subset
can take up to O(n).

Space:
    O(n) auxiliary space for the recursion and subset.
    The output itself takes O(n * 2^n).
*/
class Solution {
public:
    void backtrack(vector<int>& nums, int index, vector<int>& subset, vector<vector<int>>& rez) {
        if (index >= nums.size()) {
            rez.push_back(subset);
            return;
        }
        subset.push_back(nums[index]);
        backtrack(nums, index + 1, subset, rez);
        subset.pop_back();
        backtrack(nums, index + 1, subset, rez);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>rez;
        vector<int>subset;
        backtrack(nums, 0, subset, rez);
        return rez;
    }
};
