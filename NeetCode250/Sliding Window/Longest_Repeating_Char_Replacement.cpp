/*
Longest Repeating Character Replacement:

Use a sliding window.

Keep:
    left
    right
    freq[26]
    maxFreq = highest frequency in the window

Window size:

    right - left + 1

Characters to replace:

    windowSize - maxFreq

If:

    windowSize - maxFreq <= k

the window is valid.

Otherwise:
    shrink the window by moving left.

Update the longest valid window.

Main insight:

Keep the most frequent character and replace
all the others.

The number of replacements needed is:

    windowSize - maxFreq

Time Complexity: O(n)
Space Complexity: O(1)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26, 0);
        int left = 0;
        int maxFreq = 0;
        int longest = 0;
        for (int right = 0; right < s.size(); right++) {
            freq[s[right] - 'A']++;
            maxFreq = max(maxFreq, freq[s[right] - 'A']);
            while ((right - left + 1) - maxFreq > k) {
                freq[s[left] - 'A']--;
                left++;
            }
            longest = max(longest, right - left + 1);
        }
        return longest;
    }
};

int main() {

    Solution sol;
    string s1 = "XYYX";
    int k1 = 2;
    cout << "Example 1: " << sol.characterReplacement(s1, k1)  << endl;
    string s2 = "AAABABB";
    int k2 = 1;
    cout << "Example 2: " << sol.characterReplacement(s2, k2)  << endl;
    return 0;
}