/*
Permutations II:

Use BACKTRACKING.

We need to generate every possible ordering,
but nums can contain duplicate values.

Example:

    nums = [1,1,2]

Without handling duplicates, we could generate
the same permutation multiple times.

So first sort the array:

    [1,1,2]

At every position, we try every unused number.

We use:

    used[i]

to keep track of which element is already
in the current permutation.

The important part is skipping duplicates.

If:

    nums[i] == nums[i - 1]

and:

    nums[i - 1] has not been used

then we skip nums[i].

Why?

The previous identical number could have been
chosen at this position instead.

Choosing the second identical number first would
create a duplicate branch.

Example:

    nums = [1,1,2]

At the first position:

    choose first 1
        |
        +-- continue

    choose second 1
        |
        +-- skip

The second 1 is skipped because the first 1
has not been used yet.

However, once the first 1 IS used, we can use
the second 1.

This is important because:

    [1,1,2]

is a valid permutation.

Visual:

                    []
              /      |      \
             1       1       2
             |       X
             |    duplicate
            [1]
           /   \
          1     2
          |     |
        [1,1]  [1,2]
          |      |
         [1,1,2] [1,2,1]

The duplicate check is:

    if (i > 0 &&
        nums[i] == nums[i - 1] &&
        !used[i - 1])

        continue;

The !used[i - 1] condition is important.

If the previous identical number is already
part of the current permutation, then using
the current identical number is allowed.

Base case:

    curr.size() == nums.size()

The permutation is complete, so add it to
the result.

Time:
    O(n * n!)

There can be up to n! permutations, and copying
each permutation takes O(n).

With duplicates, the actual number of unique
permutations can be smaller.

Space:
    O(n)

The current permutation, used array, and recursion
stack require O(n).

The result itself requires additional space.
*/

class Solution {
public:
    void backtrack(vector<int>& nums,vector<int>& curr,vector<bool>& used, vector<vector<int>>& rez) {
        if (curr.size() == nums.size()) {
            rez.push_back(curr);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (used[i]) {
                continue;
            }
            if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) {
                continue;
            }
            curr.push_back(nums[i]);
            used[i] = true;
            backtrack(nums, curr, used, rez);
            used[i] = false;
            curr.pop_back();
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> rez;
        vector<int> curr;
        vector<bool> used(nums.size(), false);
        backtrack(nums, curr, used, rez);
        return rez;
    }
};