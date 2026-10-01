/*
Problem:

Given two strings word1 and word2, return the minimum number
of operations needed to transform word1 into word2.

Allowed operations:

    1. Insert a character
    2. Delete a character
    3. Replace a character

Key idea:

Use 2D Dynamic Programming.

dp[i][j] = minimum number of operations needed to transform
           the first i characters of word1 into the first j
           characters of word2.

Therefore:

    dp[m][n]

is the final answer.

Compare the current characters:

    word1[i-1]
    word2[j-1]

Important:

The DP indices start at 1, but string indices start at 0.

Therefore:

    dp[i][j] -> word1[i-1], word2[j-1]


Case 1: Characters are equal

If:

    word1[i-1] == word2[j-1]

we don't need an operation for these characters.

So:

    dp[i][j] = dp[i-1][j-1]


Case 2: Characters are different

We have three possible operations.

1. Replace:

    Replace word1[i-1] with word2[j-1]

    dp[i-1][j-1] + 1


2. Delete:

    Delete word1[i-1]

    dp[i-1][j] + 1


3. Insert:

    Insert word2[j-1] into word1

    dp[i][j-1] + 1


Take the minimum:

    dp[i][j] = 1 + min({
        dp[i-1][j-1],  // replace
        dp[i-1][j],    // delete
        dp[i][j-1]     // insert
    })


Base cases:

If word2 is empty:

    word1 -> ""

we must delete every character:

    dp[i][0] = i


If word1 is empty:

    "" -> word2

we must insert every character:

    dp[0][j] = j


Mental model:

When characters match:

    COPY / move diagonally

When characters don't match:

    REPLACE -> diagonal
    DELETE  -> up
    INSERT  -> left

Choose the operation that results in the fewest total
operations.

Time:
    O(m * n)

Space:
    O(m * n)
*/

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>> dp(m + 1,vector<int>(n + 1, 0));
        // Base cases
        for (int i = 0; i <= m; i++) {
            dp[i][0] = i;
        }
        for (int j = 0; j <= n; j++) {
            dp[0][j] = j;
        }
        // Fill the DP table
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else {
                    dp[i][j] = 1 + min({
                        dp[i - 1][j - 1], // replace
                        dp[i - 1][j],    // delete
                        dp[i][j - 1]     // insert
                        });
                }
            }
        }
        return dp[m][n];
    }
};