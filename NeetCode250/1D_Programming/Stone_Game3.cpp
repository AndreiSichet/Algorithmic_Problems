
/*
Problem:

Alice and Bob take turns taking 1, 2, or 3 stones from the
beginning of the array.

Both play optimally.

Return "Alice", "Bob", or "Tie" depending on who finishes
with the higher score.

Key idea:

Use DP based on score difference.

dp[i] = maximum score difference the current player can achieve
        over the other player starting from index i.

If the current player takes some stones, the opponent becomes
the current player for the remaining stones.

Therefore:

    my advantage = my immediate gain - opponent's best advantage

Transitions:

Take 1:

    stoneValue[i] - dp[i+1]

Take 2:

    stoneValue[i] + stoneValue[i+1] - dp[i+2]

Take 3:

    stoneValue[i] + stoneValue[i+1] + stoneValue[i+2] - dp[i+3]

So:

    dp[i] = max(
        take 1,
        take 2,
        take 3
    )

Base case:

    dp[n] = 0

When there are no stones left, neither player can gain
any additional points.

We use n + 3 positions initialized to 0 so that dp[i+1],
dp[i+2], and dp[i+3] are safe to access near the end.

We calculate backwards because dp[i] depends on future
positions.

Finally:

    dp[0] > 0 -> Alice
    dp[0] < 0 -> Bob
    dp[0] == 0 -> Tie

Time:
    O(n)

Space:
    O(n)
*/

class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> dp(n + 3, 0);
        for (int i = n - 1; i >= 0; i--) {
            dp[i] = stoneValue[i] - dp[i + 1];
            if (i + 1 < n) {
                dp[i] = max(dp[i],stoneValue[i] + stoneValue[i + 1] - dp[i + 2]);
            }
            if (i + 2 < n) {
                dp[i] = max(dp[i],stoneValue[i] + stoneValue[i + 1] + stoneValue[i + 2] - dp[i + 3]);
            }
        }
        if (dp[0] > 0) {
            return "Alice";
        }
        else if (dp[0] < 0) {
            return "Bob";
        }
        else {
            return "Tie";
        }
    }
};