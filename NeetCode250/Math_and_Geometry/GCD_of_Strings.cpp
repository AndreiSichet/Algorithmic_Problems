/*
STRING CONCATENATION + GCD - GREATEST COMMON DIVISOR OF STRINGS

Goal:
- Find the longest string x that can be repeated to construct both str1 and str2.
- Return an empty string if no such string exists.

Key idea:
- If both strings are constructed by repeating the same base string,
  their concatenations in either order must be equal:
  str1 + str2 == str2 + str1.
- If this condition holds, the length of the longest common base string
  is gcd(str1.length(), str2.length()).
- The answer is the prefix of str1 with that length.

Algorithm:
1. Check whether str1 + str2 equals str2 + str1.
   - If not, return "" because the strings do not share a common repeating base.
2. Calculate the greatest common divisor of the two string lengths.
3. Return the prefix of str1 with length gcd(str1.length(), str2.length()).

Why this works:
- If a string x divides both str1 and str2, both strings consist of
  repetitions of x.
- Repeating the same base string means concatenating str1 with str2
  produces the same result as concatenating str2 with str1.
- If the concatenations differ, no common repeating base can exist.
- If they are equal, a common repeating base exists, and the GCD of
  the lengths gives the maximum possible length of that base.
- Taking that prefix of str1 produces the longest string that divides both.

Important boundaries:
- Do not simply take the GCD of the lengths without checking concatenation.
  For example, "ABAB" and "ABAC" have lengths with a GCD of 2,
  but they do not share a common repeating base.
- If one string is shorter than the other, the same method still works.
- If both strings are identical, the entire string is a valid answer.

Complexity:
- Time: O(n + m), where n and m are the lengths of str1 and str2.
  Concatenation comparisons take O(n + m), and GCD calculation is O(log(min(n, m))).
- Space: O(n + m) for the temporary concatenated strings.
*/

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if (str1 + str2 != str2 + str1)
            return "";
        int length = gcd(str1.size(), str2.size());
        return str1.substr(0, length);
    }
};