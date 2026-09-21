
/*
Problem:

Given an integer array nums, return the length of the
longest strictly increasing subsequence.

A subsequence does NOT need to be contiguous.

Example:

    nums = [10, 9, 2, 5, 3, 7, 101, 18]

One longest increasing subsequence is:

    [2, 3, 7, 101]

Answer:

    4


Key idea:

Use 1D dynamic programming.

    dp[i] = length of the longest increasing subsequence
            that ENDS at index i

Why do we look at previous elements?

For nums[i] to be added to an increasing subsequence,
we need a previous element nums[j] such that:

    j < i
    nums[j] < nums[i]

If this is true, we can append nums[i] to the
increasing subsequence that ended at j.

Therefore:

    dp[i] = max(dp[i], dp[j] + 1)

for every j before i where:

    nums[j] < nums[i]


Base case:

Every element by itself is an increasing subsequence.

Therefore:

    dp[i] = 1

for every i.


Example:

    nums = [2, 5, 3, 7]

Start:

    dp = [1, 1, 1, 1]

At 5:

    2 < 5

    dp[1] = dp[0] + 1
          = 2

    dp = [1, 2, 1, 1]


At 3:

    2 < 3

    dp[2] = dp[0] + 1
          = 2

    dp = [1, 2, 2, 1]


At 7:

    2 < 7 -> dp[0] + 1 = 2
    5 < 7 -> dp[1] + 1 = 3
    3 < 7 -> dp[2] + 1 = 3

    dp[3] = 3

Final:

    dp = [1, 2, 2, 3]

The answer is the maximum value in dp:

    answer = 3


Important:

dp[i] does NOT mean:

    "LIS of the first i elements"

It means:

    "LIS that MUST end at index i"


This distinction is important because the best
subsequence does not necessarily end at the last element.

Example:

    nums = [1, 2, 3, 0]

    dp = [1, 2, 3, 1]

The answer is 3, even though dp[3] is only 1.

Therefore we keep a separate answer:

    answer = max(answer, dp[i])


Time:

    O(n^2)

Space:

    O(n)
*/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        // Every element can form a subsequence by itself
        vector<int> dp(n, 1);
        int answer = 1;
        // Calculate dp[i]
        for (int i = 1; i < n; i++) {
            // Check every element before i
            for (int j = 0; j < i; j++) {
                // nums[j] can come before nums[i] because the subsequence must be increasing
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i],dp[j] + 1);
                }
            }
            // The LIS can end at any position
            answer = max(answer, dp[i]);
        }
        return answer;
    }
};