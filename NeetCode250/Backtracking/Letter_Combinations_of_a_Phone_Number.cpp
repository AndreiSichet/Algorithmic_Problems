/*
Letter Combinations of a Phone Number:

Use BACKTRACKING.

Each digit maps to several letters:

    2 -> abc
    3 -> def
    4 -> ghi
    5 -> jkl
    6 -> mno
    7 -> pqrs
    8 -> tuv
    9 -> wxyz

For every digit, we choose exactly one letter.

Example:

    digits = "23"

    2 -> abc
    3 -> def

The decision tree is:

                    ""
              /      |      \
             a       b       c
           / | \   / | \   / | \
          ad ae af bd be bf cd ce cf

Each level handles one digit.

At index 0:

    choose a letter from digits[0]

At index 1:

    choose a letter from digits[1]

When:

    index == digits.size()

we have chosen one letter for every digit,
so the current string is a complete answer.

Backtracking:

    1. Get the letters for the current digit.
    2. Try every possible letter.
    3. Add the letter to curr.
    4. Recursively process the next digit.
    5. Remove the letter before trying the next one.

Example:

    digits = "23"

    curr = ""

    choose 'a'

        curr = "a"

        choose 'd'
            curr = "ad"
            add "ad"

        remove 'd'

        choose 'e'
            curr = "ae"
            add "ae"

        remove 'e'

        choose 'f'
            curr = "af"
            add "af"

    remove 'a'

    choose 'b'
        ...

The important difference from Subsets or Combinations
is that every digit MUST contribute exactly one letter.

There is no skip choice.

For each digit, we simply try every letter mapped to it.

Time:
    O(4^n * n)

Each digit has at most 4 letters.
There can be up to 4^n combinations,
and copying each combination takes O(n).

Space:
    O(n)

The current string and recursion stack use O(n).

The result itself requires additional space.
*/

class Solution {
public:
    void backtrack(string& digits, int index,string& curr, vector<string>& rez, vector<string>& letters) {
        if (index == digits.size()) {
            rez.push_back(curr);
            return;
        }
        string& chars = letters[digits[index] - '0'];
        for (char c : chars) {
            // Choose a letter for the current digit.
            curr.push_back(c);
            backtrack(digits, index + 1, curr, rez, letters);
            // Undo the choice.
            curr.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return {};
        }
        vector<string> letters = {
            "", "", "abc", "def",
            "ghi", "jkl", "mno",
            "pqrs", "tuv", "wxyz"
        };
        vector<string> rez;
        string curr;
        backtrack(digits, 0, curr, rez, letters);
        return rez;
    }
};