/*
Asteroid Collision:

Use a stack to store surviving asteroids.

A collision is only possible when:

    stack.top() > 0
    current asteroid < 0

While a collision is possible:

1. If the current asteroid is larger,
   remove the top asteroid.

2. If they have the same size,
   both explode.

3. If the stack asteroid is larger,
   the current asteroid explodes.

If the current asteroid survives
all collisions,
push it onto the stack.

Main insight:

An asteroid can collide with multiple
previous asteroids, so use a while loop.

The stack always contains the asteroids
that have survived so far.

Time Complexity: O(n)

Space Complexity: O(n)
*/
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for (int asteroid : asteroids) {
            bool destroyed = false;
            while (!st.empty() && st.top() > 0 && asteroid < 0) {
                if (st.top() < -asteroid) {
                    st.pop();
                }
                else if (st.top() == -asteroid) {
                    st.pop();
                    destroyed = true;
                    break;
                }
                else {
                    destroyed = true;
                    break;
                }
            }
            if (!destroyed)
                st.push(asteroid);
        }
        vector<int> ans(st.size());
        for (int i = st.size() - 1; i >= 0; i--) {
            ans[i] = st.top();
            st.pop();
        }
        return ans;
    }
};
void print(vector<int> v) {
    cout << "[";
    for (int i = 0; i < v.size(); i++) {
        cout << v[i];
        if (i + 1 != v.size())
            cout << ",";
    }
    cout << "]" << endl;
}
int main() {
    Solution sol;
    vector<int> a1 = { 2,4,-4,-1 };
    vector<int> a2 = { 5,5 };
    vector<int> a3 = { 7,-3,9 };
    print(sol.asteroidCollision(a1));
    print(sol.asteroidCollision(a2));
    print(sol.asteroidCollision(a3));
    return 0;
}