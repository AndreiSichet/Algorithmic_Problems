/*
Combination Sum II:

Use BACKTRACKING.

There are two choices for each element:

    1. Choose candidates[index]
       - Add it to the current combination.
       - Move to index + 1.
       - We move forward because each element can be used once.

    2. Skip candidates[index]
       - Do not add it.
       - Move to the next different value.

We sort the array first.

Example:

    candidates = [1,1,2,5]
    target = 3

After sorting:

    [1,1,2,5]

The first 1 can be chosen:

    [1]
      |
      +-- choose second 1
      |      |
      |      +-- choose 2
      |             |
      |             +-- [1,1,2] = 4
      |
      +-- skip the duplicate 1
             |
             +-- choose 2
                    |
                    +-- [1,2] = 3

The important part is skipping duplicates when we
choose NOT to use the current value.

Suppose we have:

    [1,1,2]

At the first 1, we have two possibilities:

    Choose it:
        [1]

    Skip it:
        move past ALL consecutive 1s

Why skip all duplicate 1s?

Because choosing the second 1 instead of the first 1
would produce the same combinations.

For example:

    Choose first 1 -> [1,2]

    Skip first 1 and choose second 1 -> [1,2]

These are duplicates.

So after exploring the choice where we include
candidates[index], we skip all consecutive duplicates
before exploring the exclude choice.

This is why sorting is necessary.

The backtracking structure is:

    Choose current element:

        curr.push_back(candidates[index])

        backtrack(index + 1, target - candidates[index])

        curr.pop_back()

    Skip current value:

        skip all duplicate values

        backtrack(index + 1, target)

Important difference from Combination Sum I:

    Combination Sum I:
        Can reuse the same element.

        backtrack(index, ...)

    Combination Sum II:
        Cannot reuse the same element.

        backtrack(index + 1, ...)

Base cases:

    target == 0:
        Found a valid combination.

    target < 0:
        Current combination is too large.

    index >= candidates.size():
        No elements remain.

Example:

    candidates = [10,1,2,7,6,1,5]
    target = 8

After sorting:

    [1,1,2,5,6,7,10]

Valid combinations:

    [1,1,6]
    [1,2,5]
    [1,7]
    [2,6]

No duplicate combinations are produced.

Time:
    O(2^n) approximately

There can be up to 2^n possible subsets.

Sorting takes:
    O(n log n)

Space:
    O(n)

The recursion and current combination can use
O(n) auxiliary space.

The result itself requires additional space.
*/
class Solution {
public:
	void backtrack(vector<int>candidates, int index, int target, vector<int>& curr, vector<vector<int>>& rez) {
		if (target == 0) {
			rez.push_back(curr);
			return;
		}
		if (target < 0 || index >= candidates.size()) {
			return;
		}
		curr.push_back(candidates[index]);
		backtrack(candidates, index + 1, target - candidates[index], curr, rez);
		curr.pop_back();
        // Skip all duplicates of the current value.
		while (index + 1 < candidates.size() && candidates[index] == candidates[index + 1]) {
			index++;
		}
		backtrack(candidates, index + 1, target, curr, rez);
	}
	vector<vector<int>>combinationSum2(vector<int>& candidates, int target) {
		sort(candidates.begin(), candidates.end());
		vector<vector<int>>rez;
		vector<int>curr;
		backtrack(candidates, 0, target, curr, rez);
		return rez;
	}
};