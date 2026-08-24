/*
Extra Characters in a String:

Use DYNAMIC PROGRAMMING with MEMOIZATION.

At every index, we want to find:

    minimum extra characters from index to the end

We have two choices.

Choice 1:

    Treat s[index] as an extra character.

    extra = 1 + solve(index + 1)

Choice 2:

    Try every substring starting at index.

    If the substring is in the dictionary,
    use it and continue after that word.

Example:

    s = "leetscode"

    dictionary = ["leet", "code"]

At index 0:

    "l"       -> not a word
    "le"      -> not a word
    "lee"     -> not a word
    "leet"    -> valid

Choose "leet":

    leet | scode
          ^
          index = 4

At index 4:

    "s"       -> not a word
    "sc"      -> not a word
    "sco"     -> not a word
    "scod"    -> not a word
    "scode"   -> not a word

So we must treat 's' as extra:

    leet | s | code

Result:

    1 extra character

The recursive formula is:

    dp[index] = minimum extra characters
                from index to the end

Option 1:

    1 + dp[index + 1]

Option 2:

    dp[end + 1]

for every dictionary word:

    s[index ... end]

that exists in the dictionary.

We take the minimum.

Base case:

    index == s.size()

There are no characters left, so:

    return 0

Why memoization?

The same index can be reached through different
choices.

For example:

    index = 5

could be reached after choosing different words.

But the remaining string is always the same,
so the answer from index 5 is always the same.

Store it in:

    memo[index]

Time:

    O(n^2)

For every index, we try every possible ending
position.

Dictionary lookup with unordered_set is
approximately O(1) on average.

Space:

    O(n)

For the memo array and recursion stack.

The dictionary itself requires additional space.
*/

class Solution {
public:
    int backtrack(string& s, int index, unordered_set<string>& dict, vector<int>& memo) {
        if (index == s.size()) {
            return 0;
        }
        if (memo[index] != -1) {
            return memo[index];
        }
        // Treat the current character as extra.
        int result = 1 + backtrack(s, index + 1, dict, memo);
        string word;
        for (int end = index; end < s.size(); end++) {
            word.push_back(s[end]);
            if (!dict.count(word)) {
                continue;
            }
            result = min(result, backtrack(s, end + 1, dict, memo));
        }
        memo[index] = result;
        return result;
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_set<string> dict(dictionary.begin(), dictionary.end());
        vector<int> memo(s.size(), -1);
        return backtrack(s, 0, dict, memo);
    }
};