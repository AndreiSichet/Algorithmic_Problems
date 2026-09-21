```cpp id = "x7m2qa"
/*
Problem:

Given an array of positive integers nums, determine if the
array can be divided into two subsets with equal sums.

Example:

    nums = [1, 5, 11, 5]

We can partition it into:

    subset1 = [1, 5, 5]  -> sum = 11
    subset2 = [11]       -> sum = 11

Answer:

    true


Key idea:

If the total sum is odd, it is impossible to divide it
into two equal integer sums.

Example:

    total = 11

    11 / 2 = 5.5

Therefore:

    return false


If the total sum is even, we only need to check if we can
find a subset whose sum is:

    target = total / 2

Why?

If one subset has sum = total / 2, then the remaining
elements automatically also have sum = total / 2.


So the problem becomes:

    "Can we choose some numbers that add up to target?"

This is the 0/1 Knapsack / Subset Sum problem.


DP definition:

    dp[j] = true if we can form sum j using the numbers
            processed so far


Base case:

    dp[0] = true

We can always form sum 0 by choosing no elements.


For every number nums[i], we have two choices:

    1. Skip nums[i]

    2. Take nums[i]

If we take nums[i], then we need to have already formed:

    j - nums[i]

Therefore:

    dp[j] = dp[j] || dp[j - nums[i]]


Important:

We iterate j from target DOWN to nums[i].

Why backwards?

Each number can only be used once.

If we went forwards, we could accidentally use the
same number multiple times during the same iteration.


Example:

    nums = [1, 5, 11, 5]

    total = 22
    target = 11

After processing the numbers, we want:

    dp[11] = true


Example of the transition:

Suppose:

    nums[i] = 5

To create sum 11 using this 5, we need to have already
created:

    11 - 5 = 6

So:

    dp[11] = dp[11] || dp[6]


Meaning:

    Either we could already make 11,

    OR

    we could make 6 before and add the current 5.


Time:

    O(n * target)

Space:

    O(target)
*/

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total = 0;
        // Calculate the total sum
        for (int num : nums) {
            total += num;
        }
        // Odd total cannot be divided into two equal sums
        if (total % 2 != 0) {
            return false;
        }
        int target = total / 2;
        // dp[j] = can we create sum j?
        vector<bool> dp(target + 1, false);
        // Sum 0 is always possible by choosing nothing
        dp[0] = true;
        // Process each number
        for (int num : nums) {
            // Go backwards so each number is used at most once
            for (int j = target; j >= num; j--) {
                // Either we already had sum j,or we can create j by adding num to j - num
                dp[j] = dp[j] || dp[j - num];
            }
        }
        // Can we create exactly half of the total sum?
        return dp[target];
    }
};