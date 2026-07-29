/*
Permutation in String:

A permutation has the same character frequencies,
only the order changes.

Create:

    freq1 -> frequency of s1
    freq2 -> frequency of the current window in s2

The window size is always:

    s1.length()

1. Build the frequency array for s1.
2. Build the first window in s2.
3. Compare freq1 and freq2.
4. Slide the window:
       - add the new character
       - remove the old character
5. If the frequency arrays become equal,
   a permutation exists.

Main insight:

Instead of generating all permutations,
compare character frequencies.

Time Complexity: O(n)
Space Complexity: O(1)
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) {
            return false;
        }
        vector<int> freq1(26, 0);
        vector<int> freq2(26, 0);
        // Frequency of s1
        for (char c : s1) {
            freq1[c - 'a']++;
        }
        int window = s1.size();
        // First window
        for (int i = 0; i < window; i++) {
            freq2[s2[i] - 'a']++;
        }
        if (freq1 == freq2) {
            return true;
        }
        // Slide the window
        for (int right = window; right < s2.size(); right++) {
            freq2[s2[right] - 'a']++;
            freq2[s2[right - window] - 'a']--;
            if (freq1 == freq2) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    Solution sol;
    string s1 = "abc";
    string s2 = "lecabee";
    cout << boolalpha  << sol.checkInclusion(s1, s2)<< endl;
    s1 = "abc";
    s2 = "lecaabee";
    cout << boolalpha   << sol.checkInclusion(s1, s2)    << endl;
    return 0;
}