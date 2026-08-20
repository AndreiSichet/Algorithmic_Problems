/*
Subsets II:

Use BACKTRACKING.

The difference from Subsets I is that nums can contain
duplicate values.

Example:

    nums = [1,2,2]

Without handling duplicates, we could generate:

    [1,2]
    [1,2]

These are the same subset, so we need to skip one of them.

First, sort the array:

    [1,2,2]

At every index, we have two choices:

    1. Include nums[index]
    2. Skip nums[index]

We add the current subset at every recursive call
because every subset is valid.

The important part is skipping duplicates.

After sorting:

    [1,2,2]
       ^
       duplicate

If:

    i > start
    AND
    nums[i] == nums[i - 1]

we skip nums[i].

Why i > start?

We only want to skip duplicates at the SAME
recursion level.

Example:

    nums = [1,2,2]

We want to allow:

    [2,2]

because using both 2s is a valid subset.

But we do not want two separate branches
that both create:

    [2]

Visual:

                    []
                  /    \
                [1]      []
               /   \      \
             [1,2] [1]    [2]
             /   \   \      \
         [1,2,2] [1,2]      [2,2]

The second 2 is skipped when it would create
the same choice at the same level.

Why sort?

Sorting puts equal values next to each other:

    [1,2,2,3,3]

so we can easily detect:

    nums[i] == nums[i - 1]

Important:

    Skip duplicates only when i > start.

This means:

    [2,2]

is still allowed.

We are only preventing duplicate branches
at the same recursion level.

Time:
    O(n * 2^n)

There can be up to 2^n subsets, and copying
each subset can take O(n).

Space:
    O(n)

The recursion depth and current subset can use O(n).

The result itself requires additional space.
*/

class Solution {
public:
    void backtrack(vector<int>& nums, int start, vector<int>& curr, vector<vector<int>>& rez) {
        rez.push_back(curr);
        for (int i = start; i < nums.size(); i++) {
            if (i > start && nums[i] == nums[i - 1]) {
                continue;
            }
            curr.push_back(nums[i]);
            backtrack(nums, i + 1, curr, rez);
            curr.pop_back();
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> rez;
        vector<int> curr;
        backtrack(nums, 0, curr, rez);
        return rez;
    }
};