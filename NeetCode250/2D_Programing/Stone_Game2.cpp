
/*
Problem:
Alice and Bob take the first X remaining piles, where
1 <= X <= 2 * M.

After taking X piles:
    M = max(M, X)

Initially:
    M = 1

Key idea:
Use DP based on the current position and M.

Definition:
    dp[i][M] = maximum stones the CURRENT player can get
               starting from index i with current M.

At state (i, M), we can choose:
    X = 1 ... 2 * M

If we take X piles:
    - We get the stones from piles[i] through piles[i + X - 1]
    - The opponent starts at i + X
    - New M = max(M, X)

Instead of calculating our score directly, calculate:

    our score =
        total remaining stones
        - opponent's maximum score

Using suffix sums:

    dp[i][M] =
        max(
            suffix[i] - dp[i + X][max(M, X)]
        )

for every valid X.

Base case:
    dp[n][M] = 0

because there are no piles left.

Why subtract the opponent?
If there are 20 stones remaining and the opponent can
optimally get 13, then we get:

    20 - 13 = 7

Complexity:
Time:  O(n^3)
Space: O(n^2)
*/

class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        // suffix[i] = total stones from i to the end
        vector<int> suffix(n + 1, 0);
        for (int i = n - 1; i >= 0; i--) {
            suffix[i] = suffix[i + 1] + piles[i];
        }
        // dp[i][M] = maximum stones current player can get starting at i with current M
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for (int i = n - 1; i >= 0; i--) {
            for (int M = 1; M <= n; M++) {
                int best = 0;
                // Current player can take X piles where 1 <= X <= 2 * M
                for (int X = 1; X <= 2 * M && i + X <= n; X++) {
                    int newM = max(M, X);
                    // Total remaining stones minus the opponent's best possible score
                    int current = suffix[i] - dp[i + X][newM];
                    best = max(best, current);
                }
                dp[i][M] = best;
            }
        }
        return dp[0][1];
    }
};