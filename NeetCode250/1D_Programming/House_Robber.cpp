
/*
Problem:

Find the maximum amount of money that can be robbed
without robbing two adjacent houses.

Key idea:

At every house we have two choices:

1. Skip the house:
       dp[i - 1]

2. Rob the house:
       dp[i - 2] + nums[i]

If we rob house i, we must skip house i - 1.

Therefore:

dp[i] = max(
    dp[i - 1],
    dp[i - 2] + nums[i]
)

We only need the previous two dp values,
so we can use two variables.

Time:
    O(n)

Space:
    O(1)
*/
class Solution {
public:
    int rob(vector<int>& nums) {
        int prev2 = 0;
        int prev1 = 0;
        for (int money : nums) {
            int current = max(prev1,prev2 + money);
            prev2 = prev1;
            prev1 = current;
        }
        return prev1;
    }
};