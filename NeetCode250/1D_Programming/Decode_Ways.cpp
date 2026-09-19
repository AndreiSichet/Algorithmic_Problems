
/*
Problem:

Count the number of ways to decode a string of digits.

Mapping:

    1 -> A
    2 -> B
    ...
    26 -> Z

Key idea:

At every position, we can potentially decode:

    1 digit
or
    2 digits

A single digit is valid if it is not '0'.

A two-digit number is valid if it is between 10 and 26.

Define:

    dp[i] = number of ways to decode the first i characters.

For one digit:

    if s[i - 1] != '0':
        dp[i] += dp[i - 1]

For two digits:

    number = value of s[i - 2] and s[i - 1]

    if 10 <= number <= 26:
        dp[i] += dp[i - 2]

Base case:

    dp[0] = 1

We only need the previous two dp values,
so we can use O(1) extra space.

Time:
    O(n)

Space:
    O(1)
*/

class Solution {
public:
    int numDecodings(string s) {
        int prev2 = 1;
        int prev1 = 0;
        if (s[0] != '0') {
            prev1 = 1;
        }
        for (int i = 1; i < s.size(); i++) {
            int current = 0;
            if (s[i] != '0') {
                current += prev1;
            }
            int number = (s[i - 1] - '0') * 10 + (s[i] - '0');
            if (number >= 10 && number <= 26) {
                current += prev2;
            }
            prev2 = prev1;
            prev1 = current;
        }
        return prev1;
    }
};