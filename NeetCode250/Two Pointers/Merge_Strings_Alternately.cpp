/*
Merge Strings Alternately:

Use one index i for both strings.

At every step:
	add word1[i] if i is valid
	add word2[i] if i is valid

Continue while at least one string still has characters.

If one string is longer, its remaining characters
are automatically appended.

Time Complexity: O(n + m)
Space Complexity: O(n + m)
*/
#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
	string mergeAlternately(string word1, string word2) {
		string ans;
		int i = 0;
		while (i < word1.length() || i < word2.length()) {
			if (i < word1.length()) {
				ans += word1[i];
			}
			if (i < word2.length()) {
				ans += word2[i];
			}
			i++;
		}
		return ans;
	}
};
int main() {
	Solution sol;
	string word1 = "abc";
	string word2 = "xyz";
	cout << "Example 1: "<< sol.mergeAlternately(word1, word2)<< endl;
	word1 = "ab";
	word2 = "abbxxc";
	cout << "Example 2: "<< sol.mergeAlternately(word1, word2)<< endl;
	return 0;
}