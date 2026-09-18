
/*
Problem:

Find the longest palindromic substring.

Key idea:

Every palindrome has a center.

There are two possible types of centers:

1. Odd-length palindrome:
       left = i
       right = i

2. Even-length palindrome:
       left = i
       right = i + 1

For every position, expand outward while:
    - left is inside the string
    - right is inside the string
    - s[left] == s[right]

During the expansion, keep track of the longest
palindrome found so far.

Example:

    "babad"

Odd center at index 2:

    b a b a d
        ^
      center

Expand:

    b a b a d
      ^   ^
      a   a

    b a b a d
    ^       ^
    b       b

This gives "bab".

We also check even centers to handle palindromes
such as "abba" or "bb".

Time:
    O(n^2)

Space:
    O(1)
*/

class Solution {
public:
    pair<int, int> expand(string& s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            left--;
            right++;
        }
        return { left + 1, right - 1 };
    }
    string longestPalindrome(string s) {
        int bestLeft = 0;
        int bestRight = 0;
        for (int i = 0; i < s.size(); i++) {
            pair<int, int> odd = expand(s, i, i);
            if (odd.second - odd.first > bestRight - bestLeft) {
                bestLeft = odd.first;
                bestRight = odd.second;
            }
            pair<int, int> even = expand(s, i, i + 1);
            if (even.second - even.first > bestRight - bestLeft) {
                bestLeft = even.first;
                bestRight = even.second;
            }
        }
        return s.substr(bestLeft,bestRight - bestLeft + 1);
    }
};