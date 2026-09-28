
/*
Problem:

Return true if s3 can be formed by interleaving s1 and s2.

Key idea:

dp[i][j] = true if the first i characters of s1 and the
first j characters of s2 can form the first i+j characters
of s3.

Base case:

    dp[0][0] = true

First column:

    dp[i][0]

Only s1 is being used, so s1[i-1] must match s3[i-1].

First row:

    dp[0][j]

Only s2 is being used, so s2[j-1] must match s3[j-1].

For an internal cell, there are two possibilities:

1. Take the next character from s1:

    dp[i-1][j] && s1[i-1] == s3[i+j-1]

2. Take the next character from s2:

    dp[i][j-1] && s2[j-1] == s3[i+j-1]

Therefore:

    dp[i][j] =
        (dp[i-1][j] && s1[i-1] == s3[i+j-1])
        ||
        (dp[i][j-1] && s2[j-1] == s3[i+j-1])

Time:
    O(n * m)

Space:
    O(n * m)
*/

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size();
        int m = s2.size();

        if (n + m != s3.size()) {
            return false;
        }
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
        dp[0][0] = true;
        for (int i = 1; i <= n; i++) {
            dp[i][0] = dp[i - 1][0] && s1[i - 1] == s3[i - 1];
        }
        for (int j = 1; j <= m; j++) {
            dp[0][j] = dp[0][j - 1] && s2[j - 1] == s3[j - 1];
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                dp[i][j] = (dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]) || (dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
            }
        }
        return dp[n][m];
    }
};