
/*
Problem:

Find the minimum number of coins needed to make
the exact target amount.

We have unlimited coins.

Key idea:

Let:

    dp[x] = minimum number of coins needed to make x.

To calculate dp[x], look at the last coin used.

If the last coin is coins[j], then before using it
we needed to make:

    x - coins[j]

Therefore:

    dp[x] = min(
        dp[x - coins[j]] + 1
    )

We initialize every dp value with amount + 1,
which represents an impossible amount.

Base case:

    dp[0] = 0

because zero coins are needed to make amount 0.

If dp[amount] is still amount + 1 at the end,
the amount cannot be made.

Time:
    O(amount * number of coins)

Space:
    O(amount)
*/

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for (int current = 1; current <= amount; current++) {
            for (int coin : coins) {
                if (current - coin >= 0) {
                    dp[current] = min(dp[current],dp[current - coin] + 1);
                }
            }
        }
        if (dp[amount] == amount + 1) {
            return -1;
        }
        return dp[amount];
    }
};