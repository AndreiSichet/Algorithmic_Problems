/*
Palindrome Partitioning:

Use BACKTRACKING.

We need to split the string into substrings
where every substring is a palindrome.

At every recursive call, we have a starting index.

From that index, try every possible ending index.

Example:

    s = "aab"

Starting at index 0:

    "a"   -> palindrome
    "aa"  -> palindrome
    "aab" -> not palindrome

If we choose "a":

    [a]

Then continue from index 1:

    "a" -> palindrome
    "ab" -> not palindrome

So:

    [a, a]

Then continue from index 2:

    "b" -> palindrome

Result:

    [a, a, b]

If instead we choose "aa":

    [aa]

Then continue from index 2:

    "b" -> palindrome

Result:

    [aa, b]

Final result:

    [a, a, b]
    [aa, b]

The backtracking process is:

    1. Choose a substring.
    2. Check if it is a palindrome.
    3. Add it to the current partition.
    4. Recursively partition the remaining string.
    5. Remove it before trying another substring.

Visual:

                     ""
                     |
                /----+----\
               a     aa    aab
               |     |      X
               |     |
              "a"   "aa"
               |     |
              / \    |
             a   ab  b
             |    X  |
             b       b

Only palindrome substrings create branches.

Base case:

    start == s.size()

This means the entire string has been partitioned
into palindromic substrings.

Palindrome check:

    Compare characters from both ends.

    left == right
        move both inward

    left != right
        not a palindrome

Example:

    "aba"

    a b a
    ^   ^
    equal

      b
      ^
      |
    palindrome

Time:
    O(n * 2^n)

There can be up to 2^(n-1) possible partitions,
and checking/copying substrings can add O(n).

Space:
    O(n)

The recursion depth and current partition can
use O(n) auxiliary space.

The result itself requires additional space.
*/

class Solution {
public:
    bool isPalindrome(string& s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }
    void backtrack(string& s, int start, vector<string>& curr, vector<vector<string>>& rez) {
        if (start == s.size()) {
            rez.push_back(curr);
            return;
        }
        for (int end = start; end < s.size(); end++) {
            if (!isPalindrome(s, start, end)) {
                continue;
            }
            // Choose the palindromic substring.
            curr.push_back(s.substr(start, end - start + 1));
            backtrack(s, end + 1, curr, rez);
            // Undo the choice.
            curr.pop_back();
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> rez;
        vector<string> curr;
        backtrack(s, 0, curr, rez);
        return rez;
    }
};  