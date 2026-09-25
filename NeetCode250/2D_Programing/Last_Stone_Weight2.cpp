
/*
Problem:

Given a list of stones, smash them together in any order and
return the smallest possible weight of the final stone.

Key idea:

Transform the problem into a subset partition problem.

If one group of stones has sum S, the other group has:

    total - S

The final difference is:

    (total - S) - S
    = total - 2 * S

To minimize the difference, we want S to be as large as
possible while:

    S <= total / 2

So this becomes a 0/1 subset-sum problem.

dp[j] = true if we can create a subset with sum j.

Base case:

    dp[0] = true

For every stone:

    dp[j] = dp[j] || dp[j - stone]

We iterate backwards because each stone can only be
used once.

Important:

    j >= stone

Otherwise j - stone would be negative.

After processing all stones, find the largest reachable
sum S <= total / 2.

Answer:

    total - 2 * S

Time:
    O(n * total)

Space:
    O(total)
*/

class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int total = 0;
        for (int stone : stones) {
            total += stone;
        }
        int target = total / 2;
        vector<bool> dp(target + 1, false);
        dp[0] = true;
        for (int stone : stones) {
            for (int j = target; j >= stone; j--) {
                dp[j] = dp[j] || dp[j - stone];
            }
        }
        for (int j = target; j >= 0; j--) {
            if (dp[j]) {
                return total - 2 * j;
            }
        }
        return 0;
    }
};