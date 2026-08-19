/*
Combinations:

We need to choose exactly k numbers from:

    [1, n]

For every number, we have two choices:

    1. Include the number.
    2. Don't include the number.

This is the same include/exclude pattern as Subsets.

Example:

    n = 4
    k = 2

                    []
                  /    \
                [1]      []
               /   \    /   \
            [1,2] [1] [2]    []
             ...

We only add a combination to the result
when it contains exactly k numbers.

The important difference from Subsets:

    Subsets:
        Every subset is valid.

    Combinations:
        Only subsets with exactly k elements are valid.

So:

    if comb.size() == k:
        add comb to result

We process numbers from left to right:

    i = 1
    i = 2
    i = 3
    ...
    i = n

After considering a number, we move to:

    i + 1

This guarantees that we never use the same number twice.

Example:

    n = 4
    k = 2

Valid combinations:

    [1,2]
    [1,3]
    [1,4]
    [2,3]
    [2,4]
    [3,4]

We never generate:

    [2,1]
    [3,1]

because after choosing 1, we only consider numbers
greater than 1.

Backtracking:

    Choose i:

        comb.push_back(i)
        backtrack(i + 1, ...)
        comb.pop_back()

    Skip i:

        backtrack(i + 1, ...)

The pop_back() restores the combination before
exploring the skip choice.

Time:
    O(C(n,k) * k)

There are C(n,k) valid combinations and copying
each combination takes O(k).

Space:
    O(k) auxiliary space for the current combination
    and recursion stack.

The result itself requires O(C(n,k) * k).

One optimization is to stop immediately when
comb.size() == k because we already have a valid
combination and do not need to explore further.
*/
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> comb;
        backtrack(1, n, k, comb,res);
        return res;
    }
private:
    void backtrack(int i, int n, int k, vector<int>& comb,vector<vector<int>>&res) {
        if (i > n) {
            if (comb.size() == k) {
                res.push_back(comb);
            }
            return;
        }
        comb.push_back(i);
        backtrack(i + 1, n, k, comb,res);
        comb.pop_back();
        backtrack(i + 1, n, k, comb,res);
    }
};