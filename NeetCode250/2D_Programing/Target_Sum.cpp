/*
Problem:

Given an array nums, assign + or - to every number so that
the resulting sum equals target.

Return the number of different ways.

Key idea:

Split the numbers into two groups:

    P = numbers with +
    N = numbers with -

Then:

    P - N = target
    P + N = total

Adding the equations:

    2 * P = total + target

Therefore:

    P = (total + target) / 2

So the problem becomes:

    Count how many subsets have sum (total + target) / 2.

This is a 0/1 subset sum counting problem.

dp[x] = number of ways to make sum x.

Base case:

    dp[0] = 1

For each number:

    dp[j] += dp[j - num]

We iterate backwards because each number can be used
only once.

If total + target is odd, the answer is impossible.

If abs(target) > total, the answer is also impossible.

Example:

nums = [1, 1]
target = 0

total = 2

P = (2 + 0) / 2 = 1

There are two subsets with sum 1:

    first 1
    second 1

Therefore the answer is 2.

Time:
    O(n * total)

Space:
    O(total)
*/

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int total = 0;
        for (int num : nums) {
            total += num;
        }
        if (abs(target) > total) {
            return 0;
        }
        if ((total + target) % 2 != 0) {
            return 0;
        }
        int subsetTarget = (total + target) / 2;
        vector<int> dp(subsetTarget + 1, 0);
        dp[0] = 1;
        for (int num : nums) {
            for (int j = subsetTarget; j >= num; j--) {
                dp[j] += dp[j - num];
            }
        }
        return dp[subsetTarget];
    }
};