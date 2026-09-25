
/*
Problem:

Given stock prices, maximize profit when you can make
multiple transactions.

After selling, there is a one-day cooldown before buying again.

You can own at most one stock at a time.

Key idea:

Use three DP states:

    hold
        Maximum profit while holding a stock.

    buyable
        Maximum profit while not holding a stock and
        being allowed to buy.

    cooldown
        Maximum profit while in the cooldown state
        immediately after selling.

Transitions:

    hold:
        Either keep holding or buy today.

        hold = max(oldHold,
                   oldBuyable - price)

    buyable:
        Either stay buyable or finish the cooldown.

        buyable = max(oldBuyable,
                      oldCooldown)

    cooldown:
        We sell today, so we must have been holding
        yesterday.

        cooldown = oldHold + price

Important:

Use the OLD values of all three states when calculating
the new states.

Base case:

    hold = -prices[0]
    buyable = 0
    cooldown = INT_MIN

At the end, we cannot be holding a stock, so:

    answer = max(buyable, cooldown)

Time:
    O(n)

Space:
    O(1)
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int hold = -prices[0];
        int buyable = 0;
        int cooldown = INT_MIN;
        for (int i = 1; i < prices.size(); i++) {
            int oldHold = hold;
            int oldBuyable = buyable;
            int oldCooldown = cooldown;
            hold = max(oldHold, oldBuyable - prices[i]);
            buyable = max(oldBuyable, oldCooldown);
            cooldown = oldHold + prices[i];
        }
        return max(buyable, cooldown);
    }
};