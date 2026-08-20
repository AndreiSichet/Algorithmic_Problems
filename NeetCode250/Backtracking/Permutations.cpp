/*
Permutations:

We need every possible ordering of the numbers.

Unlike Subsets and Combinations, we do not make an include/exclude decision.

Instead, at each position, we try every number that has not been used yet.

Example:

    nums = [1,2,3]

First position:

    [1]
    [2]
    [3]

If we choose 1:

    [1,2]
    [1,3]

If we choose 1, then 2:

    [1,2,3]

If we choose 1, then 3:

    [1,3,2]

We continue until the permutation contains
all numbers.

We use a used array:

    used[i] = true

to remember which numbers are already in
the current permutation.

Backtracking:

    1. Choose an unused number.
    2. Add it to curr.
    3. Mark it as used.
    4. Recursively build the next position.
    5. Remove it from curr.
    6. Mark it as unused.

The last two steps restore the state so the
number can be used in another permutation.

Example:

    nums = [1,2,3]

    curr = [1,2,3]

    We reach size 3, so we add it to the result.

    Then backtrack:

    [1,2,3]
         ^
         remove 3

    [1,2]

    Now we can try 3 in another position.

Number of permutations:

    n!

because:

    first position  -> n choices
    second position -> n - 1 choices
    third position  -> n - 2 choices
    ...
    last position   -> 1 choice

Total:

    n * (n - 1) * ... * 1
    = n!

Time:
    O(n * n!)

There are n! permutations and copying each
permutation takes O(n).

Space:
    O(n)

The current permutation and used array require O(n).
The result itself requires O(n * n!).
*/

class Solution {
public:
    void backtrack(vector<int>& nums, vector<int>& curr, vector<bool>& used, vector<vector<int>>& rez) {
        if (curr.size() == nums.size()) {
            rez.push_back(curr);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (used[i]) {
                continue;
            }
            curr.push_back(nums[i]);
            used[i] = true;
            backtrack(nums, curr, used, rez);
            used[i] = false;
            curr.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> rez;
        vector<int> curr;
        vector<bool> used(nums.size(), false);
        backtrack(nums, curr, used, rez);
        return rez;
    }
};