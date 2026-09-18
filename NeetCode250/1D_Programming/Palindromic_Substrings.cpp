
/*
Problem:

Count the number of palindromic substrings.

Key idea:

Every palindrome has a center.

There are two types of centers:

1. Odd-length palindrome:
       left = i
       right = i

2. Even-length palindrome:
       left = i
       right = i + 1

Expand outward from every center.

Every time:

    s[left] == s[right]

we found another palindrome, so increment the answer.

Example:

    "aaa"

Palindromes:

    "a"
    "a"
    "a"
    "aa"
    "aa"
    "aaa"

Total = 6

Time:
    O(n^2)

Space:
    O(1)
*/

class Solution {
public:
    int expand(string& s, int left, int right) {
        int count = 0;
        while (left >= 0 && right < s.size() && s[left] == s[right] ) {
            count++;
            left--;
            right++;
        }
        return count;
    }
    int countSubstrings(string s) {
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            ans += expand(s, i, i);
            ans += expand(s, i, i + 1);
        }
        return ans;
    }
};