/*
Problem:

Given an array of balloons, burst all balloons and maximize
the total number of coins.

If balloon i is burst, you receive:

    nums[left] * nums[i] * nums[right]

where left and right are the balloons currently adjacent
to i.

If there is no balloon on one side, use 1.

Key idea:

Use 2D Dynamic Programming.

The difficult part is that the neighbors of a balloon change
depending on the order in which we burst the balloons.

Instead of thinking about which balloon we burst FIRST,
think about which balloon we burst LAST.

For an interval [left, right]:

    dp[left][right] = maximum coins we can obtain by bursting
                      all balloons from left to right.

If k is the LAST balloon we burst in this interval, then:

    1. All balloons from left to k-1 have already been burst.
    2. All balloons from k+1 to right have already been burst.
    3. Therefore, when k is finally burst, its neighbors are
       exactly left-1 and right+1.

So:

    dp[left][right] =
        dp[left][k-1]
        + dp[k+1][right]
        + a[left-1] * a[k] * a[right+1]


Important:

Add two virtual balloons with value 1:

    a = [1, nums[0], nums[1], ..., nums[n-1], 1]

This eliminates special cases for the boundaries.

Example:

    nums = [3, 1, 5, 8]

    a = [1, 3, 1, 5, 8, 1]
         ^               ^
       virtual         virtual
          1               1


DP meaning:

    dp[left][right]

means:

    maximum coins obtainable by bursting every balloon
    between left and right, inclusive.

The interval contains the actual balloons in a.

For every interval, try every possible balloon k
as the LAST balloon to burst.

Therefore:

    dp[left][right] = max over k of:

        dp[left][k-1]
        + dp[k+1][right]
        + a[left-1] * a[k] * a[right+1]


Why do we use k as the LAST balloon?

Because if k were the FIRST balloon, its neighbors would
change after other balloons are removed.

If k is the LAST balloon, all other balloons in the interval
are already gone, so its neighbors are fixed:

    left-1 and right+1


DP order:

We need smaller intervals to be calculated before larger
intervals.

Therefore, iterate by interval length:

    len = 1
    len = 2
    len = 3
    ...

For each interval:

    [left, right]

try:

    k = left ... right


Base case:

An empty interval contains no balloons.

Therefore:

    dp[left][right] = 0

for an empty interval.

This is already handled by initializing the DP table with 0.


Example of the recurrence:

Suppose we calculate:

    dp[1][4]

and choose:

    k = 3

as the last balloon.

Then:

    dp[1][4] =
        dp[1][2]
        + dp[4][4]
        + a[0] * a[3] * a[5]


The left and right subproblems are independent because
balloon k is burst last.


Mental model:

Instead of:

    "Which balloon should I burst first?"

think:

    "Which balloon should I burst LAST?"

Then:

    LEFT SUBPROBLEM
          +
    RIGHT SUBPROBLEM
          +
    LAST BALLOON'S COINS


Important indexing:

The original nums array has indices:

    0 ... n-1

The modified array a has:

    0 ... n+1

with:

    a[0]   = 1
    a[n+1] = 1

Actual balloon nums[i]:

    a[i+1]


Time:

    O(n^3)

There are:

    O(n^2)

intervals, and for every interval we try:

    O(n)

possible last balloons.

Therefore:

    O(n^3)


Space:

    O(n^2)

for the DP table.
*/

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        // Add virtual balloons with value 1
        vector<int> a(n + 2, 1);
        for (int i = 0; i < n; i++) {
            a[i + 1] = nums[i];
        }
        // dp[left][right] = maximum coins for interval [left, right]
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
        // Process intervals from small to large
        for (int len = 1; len <= n; len++) {
            for (int left = 1; left + len - 1 <= n; left++) {
                int right = left + len - 1;
                // Try every balloon as the LAST one to burst
                for (int k = left; k <= right; k++) {
                    dp[left][right] = max( dp[left][right], dp[left][k - 1] + dp[k + 1][right] + a[left - 1] * a[k] * a[right + 1] );
                }
            }
        }
        return dp[1][n];
    }
};