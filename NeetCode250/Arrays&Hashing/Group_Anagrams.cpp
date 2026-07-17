/*
Notes:
Two strings are anagrams if every character appears the same number of times in both strings.
Use the frequency vector of 26 lowercase letters as a key.
Used (char) c-'a' to get the index of the char in the frequency vector.
After that transform the frequency vector in a frequency string to use the unordered_map data structure.
Use a separator like '#' or ',' between the frequencies when concatenating the string.
Strings with the same frequency string belong to the same group.
Use a hashmap to store groups of strings with the same frequency string.
After that traverse the map and add each group of strings to the solution.
Time Complexity: O(m*n), where m=number of strings and n=maximum length of a string
Space Complexity: O(m)

MAP VS UNORDERED_MAP

map:
- Keys are sorted.
- Implemented as a balanced binary search tree.
- Search/insert/delete: O(log n).
- Works with comparable keys, e.g. vector<int>.

unordered_map:
- Keys are not sorted.
- Implemented using a hash table.
- Search/insert/delete: O(1) on average.
- Requires a hash function for the key type.

Important:
A solution using unordered_map can often be changed to map, but the time complexity becomes O(log n) instead of O(1).

The reverse is not always possible directly because unordered_map needs a hash function for the key.

Example:
map<vector<int>, vector<string>>              // works
unordered_map<vector<int>, vector<string>>    // requires a custom hash

*/
#include <iostream>
#include <vector>
#include<map>
using namespace std;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for (string s : strs) {
            vector<int> count(26, 0);
            for (char c : s) {
                count[c - 'a']++;
            }
            string key;
            for (int i = 0; i < 26; i++) {
                key += to_string(count[i]) + "#";
            }
            mp[key].push_back(s);
        }
        vector<vector<string>> ans;
        for (auto& pair : mp) {
            ans.push_back(pair.second);
        }
        return ans;
    }
}; 
void printResult(vector<vector<string>> result) {
    for (auto& group : result) {
        cout << "[ ";
        for (string s : group) {
            cout << s << " ";
        }
        cout << "] ";
    }
    cout << endl;
}
int main() {
    vector<string> strs1 = { "act", "pots", "tops", "cat", "stop", "hat" };
    vector<string> strs2 = { "x" };
    vector<string> strs3 = { "" };
    Solution sol;
    cout << "Output1: ";
    printResult(sol.groupAnagrams(strs1));
    cout << "Output2: ";
    printResult(sol.groupAnagrams(strs2));
    cout << "Output3: ";
    printResult(sol.groupAnagrams(strs3));
}