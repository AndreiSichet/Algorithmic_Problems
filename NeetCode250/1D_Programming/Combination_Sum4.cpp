
/*
Problem:

Given an array of distinct positive integers nums and a
target, return the number of possible combinations that
add up to target.

Important:

Order matters.

For example:

    nums = [1, 2]
    target = 3

These are different combinations:

    1 + 2
    2 + 1

So both must be counted.


Key idea:

Use 1D dynamic programming.

    dp[x] = number of ways to create sum x
            using elements from nums

Base case:

    dp[0] = 1

There is exactly one way to create sum 0:

    choose nothing


For every sum x, try every number num.

If:

    num <= x

then we can use num as the LAST number.

Before using num, we need to create:

    x - num

There are:

    dp[x - num]

ways to create that previous sum.

Therefore:

    dp[x] += dp[x - num]


Example:

    nums = [1, 2]
    target = 3

Start:

    dp[0] = 1

For x = 1:

    use 1:

        dp[1] += dp[0]
        dp[1] = 1

    Combination:

        1


For x = 2:

    use 1:

        dp[2] += dp[1]

        1 + 1

    use 2:

        dp[2] += dp[0]

        2

    Therefore:

        dp[2] = 2


For x = 3:

    use 1:

        dp[3] += dp[2]

        1 + 1 + 1
        2 + 1

    use 2:

        dp[3] += dp[1]

        1 + 2

    Therefore:

        dp[3] = 3


The three combinations are:

    1 + 1 + 1
    1 + 2
    2 + 1


Important:

The order of the loops matters.

We use:

    for x:
        for num:

because order matters in this problem.

If we used:

    for num:
        for x:

we would count combinations without distinguishing
different orders, which is the approach used in Coin Change.


The key recurrence:

    dp[x] += dp[x - num]

Think:

    ways to make x

        =

    ways to make x - num
    + append num at the end


Time:

    O(target * nums.size())

Space:

    O(target)
*/

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int>dp(target + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= target; i++) {
            for (int num : nums) {
                if (num <= i) {
                    dp[i] += dp[i - num];
                }
            }
        }
        return dp[target];
    }
};