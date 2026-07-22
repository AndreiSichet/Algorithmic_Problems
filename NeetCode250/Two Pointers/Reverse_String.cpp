/*
Reverse String:

Use two pointers:

    left  -> first character
    right -> last character

Swap the characters, then move:
    left++
    right--

Continue while:
    left < right

The vector is modified in-place.

Time Complexity: O(n)
Space Complexity: O(1)
*/
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	void reverseString(vector<char>& s) {
		int left = 0;
		int right = s.size() - 1;
		while (left < right) {
			swap(s[left], s[right]);
			left++;
			right--;
		}
	}
};
int main() {
    Solution sol;
    vector<char> s1 = { 'n', 'e', 'e', 't' };
    sol.reverseString(s1);
    cout << "Example 1: ";
    for (char c : s1) {
        cout << c << " ";
    }
    cout << endl;
    vector<char> s2 = { 'r', 'a', 'c', 'e', 'c', 'a', 'r' };
    sol.reverseString(s2);
    cout << "Example 2: ";
    for (char c : s2) {
        cout << c << " ";
    }
    cout << endl;
    return 0;
}