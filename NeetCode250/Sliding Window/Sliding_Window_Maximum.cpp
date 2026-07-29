/*
Sliding Window Maximum:

Use a deque that stores indices.

The deque is kept in decreasing order
of values.

For each element:

1. Remove indices that are outside
   the current window.

2. Remove smaller values from the back,
   because they can never become the
   maximum again.

3. Insert the current index.

4. Once the window has size k,
   the maximum is always at:

       nums[dq.front()]

Main insight:

The deque stores only useful candidates
for the maximum.

The front always contains the maximum
of the current window.

Time Complexity: O(n)

Space Complexity: O(k)
*/
#include <iostream>
#include <vector>
#include <deque>
using namespace std;
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            while (!dq.empty() && dq.front() <= i - k)
                dq.pop_front();
            while (!dq.empty() && nums[dq.back()] < nums[i])
                dq.pop_back();
            dq.push_back(i);
            if (i >= k - 1)
                ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};
int main() {
    Solution sol;
    vector<int> nums = { 1,2,1,0,4,2,6 };
    vector<int> ans =sol.maxSlidingWindow(nums, 3);
    for (int x : ans)
        cout << x << " ";
    return 0;
}