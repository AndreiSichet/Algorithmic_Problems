/*
Decode String:

Use a stack of characters.

Scan the string from left to right.

If the current character is not ']':
    push it onto the stack.

When ']' is found:

    1. Pop characters until '['
       to build the encoded substring.

    2. Reverse the substring because
       it was popped in reverse order.

    3. Remove '['.

    4. Pop all digits before '['
       to get the repetition number.

    5. Reverse the digits and convert
       them to an integer.

    6. Push the substring back onto
       the stack 'k' times.

After processing the entire string,
pop everything from the stack to
build the answer.

Reverse the answer because the stack
returns characters in reverse order.

Main insight:

The stack naturally handles nested
expressions.

Whenever a closing bracket ']'
is reached, everything needed to
decode that section is already on
top of the stack.

Important details:

- Reverse the substring after popping.
- Reverse the number string before stoi().
- Push each character of the decoded
  substring individually.
- Use while(num > 0), not >= 0.

Time Complexity:
O(n + output length)

Space Complexity:
O(n)
*/
#include<iostream>
#include<string>
#include<stack>
using namespace std;
class Solution {
public:
    string decodeString(string s) {
        stack<char> st;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != ']') {
                st.push(s[i]);
            }
            else {
                string sub = "";
                while (st.top() != '[') {
                    sub += st.top();
                    st.pop();
                }
                reverse(sub.begin(), sub.end());
                st.pop(); // remove '['
                string k = "";
                while (!st.empty() && isdigit(st.top())) {
                    k += st.top();
                    st.pop();
                }
                reverse(k.begin(), k.end());
                int num = stoi(k);
                while (num > 0) {
                    for (char c : sub)
                        st.push(c);
                    num--;
                }
            }
        }
        string ans = "";
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
}; int main() {
	string s1 = "2[a3[b]]c";
	string s2 = "axb3[z]4[c]";
	string s3 = "ab2[c]3[d]1[x]";
	Solution sol;
	cout << "Output1: " << sol.decodeString(s1)<<endl;
	cout << "Output2: " << sol.decodeString(s2) << endl;
	cout << "Output3: " << sol.decodeString(s3) << endl;
}