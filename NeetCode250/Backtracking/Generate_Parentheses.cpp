/*
Generate Parentheses:

Use BACKTRACKING.

For n pairs of parentheses, we need to place:

    n opening parentheses
    n closing parentheses

We build the string one character at a time.

At every step, we have two possible choices:

    1. Add '('
    2. Add ')'

But we can only make a choice if it keeps the
string potentially valid.

Rules:

    We can add '(' if:

        open < n

    We can add ')' if:

        close < open

Why can close never be greater than open?

Because that would create an invalid prefix.

Example:

    ")("

The first character is already invalid.

So we always need:

    close <= open

Visual for n = 2:

                    ""
                  /    \
                "("     X
               /   \
            "(("    "()"
             |        |
            (()      ()
             |        |
            (())     ()()

The valid results are:

    (())
    ()()

Backtracking:

    Add '(':
        increase open

    Add ')':
        increase close

When:

    open == n
    close == n

the string is complete, so add it to
the result.

Example with n = 3:

    ((()))
    (()())
    (())()
    ()(())
    ()()()

The important idea is that we never generate
an invalid string and then try to fix it.

We only make choices that can still lead to
a valid answer.

Time:
    O(4^n / sqrt(n))

There are Catalan number C_n valid parentheses
strings, and each string has length 2n.

Space:
    O(n)

The recursion depth is at most 2n, so auxiliary
space is O(n).

The result itself requires additional space.
*/

class Solution {
public:
    void backtrack(int n, int open, int close, string& curr, vector<string>& rez) {
        if (open == n && close == n) {
            rez.push_back(curr);
            return;
        }
        if (open < n) {
            // Add an opening parenthesis.
            curr.push_back('(');
            backtrack(n, open + 1, close, curr, rez);
            curr.pop_back();
        }
        if (close < open) {
            // Add a closing parenthesis.
            curr.push_back(')');
            backtrack(n, open, close + 1, curr, rez);
            curr.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> rez;
        string curr;
        backtrack(n, 0, 0, curr, rez);
        return rez;
    }
};