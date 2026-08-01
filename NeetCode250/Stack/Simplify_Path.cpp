/*
Simplify Path:
Use a stack to represent
the current directory path.

Instead of scanning character
by character manually, use
stringstream + getline to split
the path on '/' into tokens.

For each token:
""   -> ignore
"."  -> ignore
".." -> pop if possible
otherwise -> push the directory name

After processing all tokens,
rebuild the path by joining
the stack contents with '/'.

Main insight:
The stack always represents
the current valid path.
Entering a directory:
    push.
Going to the parent:
    pop.

Ignore repeated slashes and "."
because they do not change the path.
Only ".." moves up one directory.

Strings like "...", "....", etc.
are treated as normal directory names.

-------------------------------------------------
Guide: stringstream + getline for splitting strings
-------------------------------------------------

stringstream lets you treat a string
like an input stream, so you can pull
pieces out of it the same way you'd
read tokens from cin.

    #include <sstream>
    stringstream ss(path);

getline(stream, buffer, delimiter)
reads from the stream into buffer,
stopping at each occurrence of
delimiter (instead of '\n' by default).

    string part;
    while (getline(ss, part, '/')) {
        // part now holds the text
        // between two slashes
    }

Example: path = "/a//b/../c"

getline splits this into:
    ""      (before the first '/')
    "a"
    ""      (from the double slash "//")
    "b"
    ".."
    "c"

Each empty string comes from two
delimiters in a row (or a leading '/'),
so they get filtered out by the
part == "" check.

getline returns false once the
stream is exhausted, which naturally
ends the while loop -- no need to
manually loop to i <= path.size()
like in the character-by-character
version.

This makes stringstream + getline
a clean way to "split by delimiter"
in C++, similar to Python's
path.split('/').

-------------------------------------------------

Time Complexity: O(n)
Space Complexity: O(n)
*/
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
class Solution {
public:
    string simplifyPath(string path) {
        stack<string> stk;
        stringstream ss(path);
        string part;
        while (getline(ss, part, '/')) {
            if (part == "" || part == ".") {
                continue;
            }
            else if (part == "..") {
                if (!stk.empty()) stk.pop();
            }
            else {
                stk.push(part);
            }
        }
        // std::stack only exposes top()/pop(), so we can't
        // index into it to rebuild the path in order.
        // Popping unloads it top-to-bottom (reverse order),
        // so we collect into a vector, then reverse that
        // vector to restore the original push order.
        vector<string> parts;
        while (!stk.empty()) {
            parts.push_back(stk.top());
            stk.pop();
        }
        reverse(parts.begin(), parts.end());
        string result = "/";
        for (int i = 0; i < parts.size(); i++) {
            result += parts[i];
            if (i != parts.size() - 1) result += "/";
        }
        return result;
    }
};
int main() {
    Solution sol;
    cout << sol.simplifyPath("/neetcode/practice//...///../courses") << endl;
    cout << sol.simplifyPath("/..//") << endl;
    cout << sol.simplifyPath("/..//_home/a/b/..///") << endl;
    return 0;
}