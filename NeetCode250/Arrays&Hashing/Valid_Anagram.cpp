/*
Notes:
First evaluate the base case, if the lengths are not the same they cannot be anagrams.
Afterwards use a hashmap to store the frequencies of every char in the first string.
Iterate through the second string and for every char in t subtract 1 from the char's frequency in the hashmap.
If you get a negative frequency that means there is a char in t that does not appear in s therefore the strings are not anagrams.
Time Complexity: O(n)
Space Complexity: O(n)
*/

#include <iostream>
#include <vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        unordered_map<char, int>freq;
        for (char c : s) {
            freq[c]++;
        }
        for (char c : t) {
            freq[c]--;
            if (freq[c] < 0) {
                return false;
            }
        }
        return true;
    }
};
int main() {
    string s1 = "racecar", t1 = "carrace";
    string s2 = "jar", t2 = "jam";
    Solution sol;
    cout << "Output1: " << sol.isAnagram(s1, t1) << " Output2: " << sol.isAnagram(s2, t2);
}