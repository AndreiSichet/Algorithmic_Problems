
/*
Problem:

Given an amount and coin denominations, return the number of
different combinations that make up the amount.

The order of coins does not matter.

Key idea:

Use 1D Dynamic Programming.

dp[i] = number of combinations that make amount i.

Base case:

dp[0] = 1

There is exactly one way to make 0:
choose nothing.

For every coin, try to use it to build larger amounts.

If we use coin as the last coin:

    i = (i - coin) + coin

Every combination that makes i - coin can create a
combination for i by adding coin.

So:

    dp[i] += dp[i - coin]

Important:

The coin loop must be OUTSIDE the amount loop.

This prevents counting:

    1 + 2

and

    2 + 1

as different combinations.

The amount loop goes FORWARD because each coin can be
used unlimited times.

Example:

coins = [1, 2, 5]
amount = 5

Valid combinations:

    5
    2 + 2 + 1
    2 + 1 + 1 + 1
    1 + 1 + 1 + 1 + 1

Answer = 4

Time:
    O(amount * coins.size())

Space:
    O(amount)
*/

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;
        for (int coin : coins) {
            for (int i = coin; i <= amount; i++) {
                dp[i] += dp[i - coin];
            }
        }
        return dp[amount];
    }
};