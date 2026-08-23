/*
Word Break II:

Use BACKTRACKING with MEMOIZATION.

We start at an index in s.

From that index, try every possible substring:

    s[start ... end]

If the substring is in wordDict, choose it and continue from:

    end + 1

Example:

    s = "catsanddog"

    wordDict = ["cat", "cats", "and", "sand", "dog"]

Starting at index 0:

    "cat"  -> valid
    "cats" -> valid

Choose "cat":

    cat | sand | dog

Choose "cats":

    cats | and | dog

So the result is:

    "cat sand dog"
    "cats and dog"

Backtracking:

    1. Choose a valid dictionary word.
    2. Add it to the current sentence.
    3. Recursively solve the remaining string.
    4. Remove the word before trying another word.

The important part is memoization.

Suppose multiple paths reach the same index:

    s = "........X"

If we reach X from different previous words, the possible sentences after X are exactly the same.

So we store:

    memo[start]

which contains all possible sentences that can
be constructed from s[start] to the end.

Base case:

    start == s.size()

There is one valid way to finish the string:

    ""

We return an empty suffix so the previous word can be added without an extra space.

For example:

    choose "dog"

    remaining sentence = ""

    "cat" + " " + "dog"

When combining results:

    If next sentence is empty:
        current word

    Otherwise:
        current word + " " + next sentence

Why use a set?

wordDict can be given as a vector, but looking up whether a word exists should be fast.

So we convert it to:

    unordered_set<string>

Time:
    Depends on the number of possible sentences
    and substring operations.

Memoization prevents repeatedly solving the
same suffix.

Space:
    O(n) recursion depth, plus the memoized results.
    The returned sentences can require much more
    space.
*/

class Solution {
public:
    vector<string> backtrack(string& s, int start, unordered_set<string>& dict, unordered_map<int, vector<string>>& memo) {
        if (start == s.size()) {
            return { "" };
        }
        if (memo.count(start)) {
            return memo[start];
        }
        vector<string> result;
        string word;
        for (int end = start; end < s.size(); end++) {
            word.push_back(s[end]);
            if (!dict.count(word)) {
                continue;
            }
            vector<string> next = backtrack(s, end + 1, dict, memo);
            for (string& sentence : next) {
                if (sentence.empty()) {
                    result.push_back(word);
                }
                else {
                    result.push_back(word + " " + sentence);
                }
            }
        }
        memo[start] = result;
        return result;
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        unordered_map<int, vector<string>> memo;
        return backtrack(s, 0, dict, memo);
    }
};