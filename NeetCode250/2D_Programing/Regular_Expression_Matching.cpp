/*
Problem:

Given a string s and a pattern p, determine whether p matches
the ENTIRE string s.

The pattern contains:

    lowercase letters
    '.'
    '*'

Rules:

    '.' -> matches any single character

    '*' -> matches zero or more occurrences of the
           character immediately before it.


Examples:

    s = "aa"
    p = "a"

    -> false


    s = "aa"
    p = "a*"

    -> true

    because 'a*' can match:

        ""
        "a"
        "aa"


    s = "ab"
    p = ".*"

    -> true

    because:

        '.' -> matches 'a'
        '*' -> allows zero or more characters matching '.'


Key idea:

Use 2D Dynamic Programming.

Define:

    dp[i][j] = true if the first i characters of s
               match the first j characters of p.

Therefore:

    dp[m][n]

is the final answer.


Important indexing:

DP indices start at 1, while strings start at 0.

Therefore:

    s[i-1]
    p[j-1]

represent the current characters.


Base case:

An empty string and an empty pattern match:

    dp[0][0] = true


Case 1: Current pattern character is NOT '*'

Suppose:

    p[j-1] != '*'

Then the current characters must match.

There are two possibilities:

    s[i-1] == p[j-1]

or:

    p[j-1] == '.'

If either is true:

    dp[i][j] = dp[i-1][j-1]


Why?

If the current characters match, we remove both
characters and check whether the remaining prefixes match.


Case 2: Current pattern character IS '*'

Suppose:

    p[j-1] == '*'

The '*' operates on the character before it:

    p[j-2]

There are TWO possibilities.


Option 1: '*' matches ZERO occurrences

We simply ignore:

    x*

Both characters are removed from consideration.

Therefore:

    dp[i][j] = dp[i][j-2]


Example:

    s = "abc"
    p = "ab*c"

The 'b*' can match zero b's.


Option 2: '*' matches ONE OR MORE occurrences

For this to be possible, the current string character:

    s[i-1]

must match the character before '*':

    p[j-2]

The character matches if:

    s[i-1] == p[j-2]

or:

    p[j-2] == '.'


If they match:

    dp[i][j] = dp[i-1][j]


Why dp[i-1][j]?

Because we consume one character from s, but KEEP
the same pattern.

This allows '*' to consume another character.

Example:

    s = "aaa"
    p = "a*"

We can repeatedly use:

    dp[i-1][j]

to let 'a*' consume:

    "a"
    "aa"
    "aaa"


Therefore, when p[j-1] == '*':

    dp[i][j] =
        dp[i][j-2]
        ||
        (current character matches p[j-2]
         && dp[i-1][j])


Full recurrence:

If p[j-1] != '*':

    if s[i-1] == p[j-1] || p[j-1] == '.':
        dp[i][j] = dp[i-1][j-1]


If p[j-1] == '*':

    zero occurrences:

        dp[i][j] = dp[i][j-2]

    OR

    one/more occurrences:

        if s[i-1] == p[j-2] || p[j-2] == '.':
            dp[i][j] |= dp[i-1][j]


Base cases for an empty string:

We need to determine whether the pattern can match "".

Only patterns consisting of pairs such as:

    a*
    a*b*
    a*b*c*

can match an empty string.

Therefore:

    dp[0][j] = dp[0][j-2]

if:

    p[j-1] == '*'


Example:

    p = "a*b*c*"

    "" can match "a*b*c*"

because every '*' chooses zero occurrences.


Mental model:

Normal character / '.':

    MATCH ONE CHARACTER
    move diagonally:

        dp[i-1][j-1]
             |
             v
        dp[i][j]


'*':

    ZERO occurrences:
        remove x*
        move LEFT TWO:

        dp[i][j-2]


    ONE OR MORE occurrences:
        consume one character from s
        keep the same pattern:

        dp[i-1][j]


The most important thing to remember:

    '*' ALWAYS belongs to the character immediately before it.

So for:

    "a*"

the '*' controls 'a'.

For:

    ".*"

the '*' controls '.'.


Time:

    O(m * n)

where:

    m = s.size()
    n = p.size()


Space:

    O(m * n)

because we store the entire DP table.
*/
class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        vector<vector<bool>> dp(m + 1,vector<bool>(n + 1, false));
        // Empty string matches empty pattern
        dp[0][0] = true;
        // Handle patterns that can match an empty string
        for (int j = 2; j <= n; j++) {
            if (p[j - 1] == '*') {
                dp[0][j] = dp[0][j - 2];
            }
        }
        // Fill the DP table
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                // Case 1: Current pattern character is not '*'
                if (p[j - 1] != '*') {
                    if (s[i - 1] == p[j - 1] || p[j - 1] == '.') {
                        dp[i][j] = dp[i - 1][j - 1];
                    }
                }
                // Case 2: Current pattern character is '*'
                else {
                    // Option 1: '*' matches zero occurrences
                    dp[i][j] = dp[i][j - 2];
                    // Option 2: '*' matches one or more occurrences
                    if (s[i - 1] == p[j - 2] || p[j - 2] == '.') {
                        dp[i][j] = dp[i][j] || dp[i - 1][j];
                    }
                }
            }
        }
        return dp[m][n];
    }
};