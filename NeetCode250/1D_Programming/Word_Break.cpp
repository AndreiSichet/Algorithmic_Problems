
/*
Problem:

Given a string s and a dictionary of words, determine
if s can be segmented into dictionary words.

Words from the dictionary can be reused unlimited times.

Key idea:

Use 1D dynamic programming.

    dp[i] = true if the first i characters of s
            can be completely segmented

For every position i, we try every possible position j
where the LAST word could start.

The string is divided into:

    s[0 ... j-1] | s[j ... i-1]
       previous       last word

For dp[i] to be true, both conditions must be satisfied:

    1. dp[j] == true
       The previous part can already be segmented.

    2. s[j ... i-1] is in the dictionary.
       The last part is a valid word.

Therefore:

    dp[i] = dp[j] && (s[j ... i-1] is in wordDict)

If any j works, then dp[i] is true.

Base case:

    dp[0] = true

The first 0 characters form an empty string, which is
considered successfully segmented.

Example:

    s = "leetcode"
    wordDict = ["leet", "code"]

    dp[0] = true

    "leet" is a dictionary word:

        dp[4] = dp[0] && "leet" exists
              = true

    "code" is a dictionary word:

        dp[8] = dp[4] && "code" exists
              = true

Therefore:

    dp[8] = true

Important:

The DP state represents the FIRST i characters.

So:

    dp[4]

means:

    "Can s[0..3] be segmented?"

It does NOT mean:

    "Can s[4] be segmented?"

Time:

    O(n^2 * L)

where L is the cost of creating/checking a substring.

Space:

    O(n + dictionary size)
*/

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        // Store dictionary words for fast lookup
        unordered_set<string> words(wordDict.begin(),wordDict.end());
        vector<bool> dp(n + 1, false);
        // Empty string can always be segmented
        dp[0] = true;
        // Try every possible ending position
        for (int i = 1; i <= n; i++) {
            // Try every possible starting position of the last word
            for (int j = 0; j < i; j++) {
                string word = s.substr(j, i - j);
                // Previous part must be valid and the last word must be in the dictionary
                if (dp[j] && words.count(word)) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};