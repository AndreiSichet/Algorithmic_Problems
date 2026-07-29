/*
Minimum Window Substring:

Use a sliding window.

Store:

    need   -> frequencies of characters in t
    window -> frequencies in the current window

Keep:

    have      -> number of characters whose
                 required frequency is satisfied

    needCount -> number of distinct characters
                 in t

Expand the window by moving right.

Whenever:

    window[c] == need[c]

increase:

    have

When:

    have == needCount

the window contains every required character.

Try to shrink the window from the left
while it is still valid.

Update the shortest valid window.

Main insight:

Expand until the window becomes valid.

Then shrink as much as possible while
keeping it valid.

Time Complexity: O(n)

Space Complexity: O(m)

where m is the number of distinct characters.
*/
#include <iostream>
#include <string>
#include <unordered_map>
#include <climits>
using namespace std;
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> need;
        unordered_map<char, int> window;
        for (char c : t)
            need[c]++;
        int have = 0;
        int needCount = need.size();
        int left = 0;
        int minLength = INT_MAX;
        int start = 0;
        for (int right = 0; right < s.size(); right++) {
            char c = s[right];
            window[c]++;
            if (need.count(c) && window[c] == need[c]) {
                have++;
            }
            while (have == needCount) {
                if (right - left + 1 < minLength) {
                    minLength = right - left + 1;
                    start = left;
                }
                window[s[left]]--;
                if (need.count(s[left]) && window[s[left]] < need[s[left]]) {
                    have--;
                }
                left++;
            }
        }
        if (minLength == INT_MAX)
            return "";
        return s.substr(start, minLength);
    }
};
int main() {
    Solution sol;
    cout << sol.minWindow("OUZODYXAZV", "XYZ") << endl;
    cout << sol.minWindow("xyz", "xyz") << endl;
    cout << "\"" << sol.minWindow("x", "xy") << "\"" << endl;
    return 0;
}