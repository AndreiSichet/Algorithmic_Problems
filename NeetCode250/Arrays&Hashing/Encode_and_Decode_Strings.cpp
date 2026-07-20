/*
Encode and Decode Strings:

Use the format:

    length#string

Example:

    ["Hello", "World"]

becomes:

    "5#Hello5#World"

ENCODE:
For every string:
    1. Add its length.
    2. Add '#'.
    3. Add the actual string.

DECODE:
    1. Find the '#' separator.
    2. Read the number before '#'.
    3. Convert it to an integer.
    4. Read exactly that many characters after '#'.
    5. Move to the next encoded string.

Example:

    "5#Hello5#World"

    5#Hello  -> "Hello"
    5#World  -> "World"

Empty string:

    [""]

    becomes:

    "0#"

The length tells us exactly how many characters
belong to each string.

The separator '#' can also appear inside the original string,
because we do not use '#' alone to find the end of a string.
We use the length.

Time Complexity:
Encode: O(n)
Decode: O(n)

Space Complexity: O(n)
*/
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    string encode(vector<string>& strs) {
        string encoded;
        for (string s : strs) {
            encoded += to_string(s.size());
            encoded += "#";
            encoded += s;
        }
        return encoded;
    }
    vector<string> decode(string s) {
        vector<string> result;
        int i = 0;
        while (i < s.size()) {
            int j = i;
            // Find the separator '#'
            while (s[j] != '#') {
                j++;
            }
            // Convert the length from string to integer
            int length = stoi(s.substr(i, j - i));
            // Start of the actual string
            int start = j + 1;
            // Extract exactly 'length' characters
            result.push_back(s.substr(start, length));
            // Move to the next encoded string
            i = start + length;
        }
        return result;
    }
};
int main() {
    Solution codec;

    // Input 1
    vector<string> strs1 = { "Hello", "World" };

    string encoded1 = codec.encode(strs1);
    vector<string> decoded1 = codec.decode(encoded1);

    cout << "Input 1:" << endl;
    cout << "Encoded: " << encoded1 << endl;

    cout << "Decoded: ";
    for (string s : decoded1) {
        cout << "[" << s << "] ";
    }

    cout << endl << endl;

    // Input 2
    vector<string> strs2 = { "" };

    string encoded2 = codec.encode(strs2);
    vector<string> decoded2 = codec.decode(encoded2);

    cout << "Input 2:" << endl;
    cout << "Encoded: " << encoded2 << endl;

    cout << "Decoded: ";
    for (string s : decoded2) {
        cout << "[" << s << "] ";
    }

    cout << endl;

    return 0;
}