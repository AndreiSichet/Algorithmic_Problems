
/*
Problem:

Given two strings, return the length of their longest
common subsequence.

Key idea:

Use 2D Dynamic Programming.

dp[i][j] = length of the LCS between the first i characters
           of text1 and the first j characters of text2.

If the current characters match:

    text1[i-1] == text2[j-1]

then we can include that character:

    dp[i][j] = dp[i-1][j-1] + 1

If they do not match, we have two choices:

    1. Ignore text1[i-1]
       dp[i-1][j]

    2. Ignore text2[j-1]
       dp[i][j-1]

So:

    dp[i][j] = max(dp[i-1][j], dp[i][j-1])

Base case:

    dp[0][j] = 0
    dp[i][0] = 0

The LCS between any string and an empty string is 0.

Important:

The DP indices start at 1, but string indices start at 0.

Therefore:

    dp[i][j] -> text1[i-1], text2[j-1]

Time:
    O(m * n)

Space:
    O(m * n)
*/

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else {
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                }
            }
        }
        return dp[m][n];
    }
};