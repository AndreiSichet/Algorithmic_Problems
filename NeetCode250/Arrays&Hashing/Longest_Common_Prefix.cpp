/*
Notes:
First take the first string as the prefix candidate.
Then compare the prefix with all the other strings in the vector using find() function.
The find() function return the first occurance of a substring in a string.
If it is not a valid prefix, the find() function !=0, shorten the prefix until the find() function return 0.
After that the loop compares it against the next string in the vector.
Time Complexity: O(n*m), where n=number of strings and m=the length of the strings
Space Complexity: O(1)
*/
#include<iostream>
#include <vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        string prefix = strs[0];
        for (string s : strs) {
            while (s.find(prefix) != 0) {
                 prefix.pop_back();
            }
        }
    }
};
int main() {
    vector<string>strs1 = { "bat","bag","bank","band" };
    vector<string> strs2 = { "dance","dag","danger","damage" };
    vector<string> strs3 = { "neet","feet" };
    Solution sol;
    cout << "Output1: " << sol.longestCommonPrefix(strs1)<<endl;
    cout << "Output2: " << sol.longestCommonPrefix(strs2) << endl;
    cout << "Output3: " << sol.longestCommonPrefix(strs3) << endl;
}