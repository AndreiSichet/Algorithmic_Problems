/*
Longest Substring Without Repeating Characters:

Use a sliding window.

Keep:
    left  -> beginning of the window
    right -> end of the window

Use an unordered_set to store the characters
currently inside the window.

For each character:

If it already exists in the window,
move left forward and remove characters
until the duplicate is removed.

Then insert the current character.

Update the answer:

    longest = max(longest, right - left + 1)

Main insight:

The window always contains unique characters.

Time Complexity: O(n)
Space Complexity: O(min(n, charset))
*/
#include <iostream>
#include <string>
#include <unordered_set>
#include <algorithm>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> window;
        int left = 0;
        int longest = 0;
        for (int right = 0; right < s.size(); right++) {
            while (window.count(s[right])) {
                window.erase(s[left]);
                left++;
            }
            window.insert(s[right]);
            longest = max(longest, right - left + 1);
        }
        return longest;
    }
};
int main() {
    Solution sol;
    string s1 = "zxyzxyz";
    string s2 = "xxxx";
    cout << "Example 1: "  << sol.lengthOfLongestSubstring(s1) << endl;
    cout << "Example 2: "  << sol.lengthOfLongestSubstring(s2) << endl;
    return 0;
}