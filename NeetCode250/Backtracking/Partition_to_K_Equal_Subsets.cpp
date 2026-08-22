/*Partition to K Equal Sum Subsets :

Use BACKTRACKING.

First calculate the total sum.

Every subset must have the same sum, so:

target = total / k

If :

total % k != 0

then it is impossible.

Example :

    nums = [4, 3, 2, 3, 5, 2, 1]
    k = 4

    total = 20
    target = 5

    We need to create :

[5]
[5]
[5]
[5]

We keep an array :

subsets = [0, 0, 0, 0]

Each value represents the current sum of one subset.

For every number, we try putting it into each subset.

Example:

number = 3

subsets = [4, 0, 0, 0]

We cannot put 3 into subset 0:

4 + 3 > 5

So we try subset 1:

subsets = [4, 3, 0, 0]

Then continue recursively.

Backtracking :

    1. Choose a subset.
    2. Add the number to that subset.
    3. Recursively place the next number.
    4. Remove the number if the choice fails.

    The important condition is :

subsets[i] + nums[index] <= target

We never allow a subset to exceed the target.

When :

    index == nums.size()

    every number has been assigned.

    Because we never allow a subset to exceed target,
    and the total sum is exactly k* target,
    all subsets must have sum target.

    Why sort in descending order ?

    sort(nums.rbegin(), nums.rend());

We place the largest numbers first.

Large numbers have fewer possible positions,
so failures are discovered earlier.

Important optimization :

if (subsets[i] == 0)
break;

If we tried putting a number into an empty subset
and that choice failed, trying another empty subset
would produce exactly the same situation.

Example:

subsets = [5, 0, 0, 0]

The last three subsets are identical.

Trying the number in subset 1, subset 2, or subset 3
creates equivalent branches.

So after trying the first empty subset, we can stop.

Time:
O(k ^ n) in the worst case.

Each of n numbers can potentially be placed
into one of k subsets.

Sorting adds O(n log n).

Space:
    O(n + k)

        O(n) for the recursion depth and O(k) for
        the subset sums.
*/
class Solution {
public:
    bool backtrack(vector<int>& nums, int index, vector<int>& subsets, int target) {
        if (index == nums.size()) {
            return true;
        }
        for (int i = 0; i < subsets.size(); i++) {
            if (subsets[i] + nums[index] > target) {
                continue;
            }
            subsets[i] += nums[index];
            if (backtrack(nums, index + 1, subsets, target)) {
                return true;
            }
            subsets[i] -= nums[index];
            if (subsets[i] == 0) {
                break;
            }
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int total = 0;
        for (int num : nums) {
            total += num;
        }
        if (total % k != 0) {
            return false;
        }
        int target = total / k;
        sort(nums.rbegin(), nums.rend());
        vector<int> subsets(k, 0);
        return backtrack(nums, 0, subsets, target);
    }
};