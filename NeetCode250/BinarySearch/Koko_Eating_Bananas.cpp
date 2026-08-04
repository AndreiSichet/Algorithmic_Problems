/*
Koko Eating Bananas:

Binary Search on the Answer.

Search for the minimum eating
speed k.

Search range:

left = 1

right = largest pile

For each candidate speed:

    Compute the total hours
    needed to eat all piles.

    hours += ceil(pile/speed)

Use integer arithmetic:

(pile + speed - 1) / speed

If hours <= h:

    The speed works.

    Save it and try
    a smaller speed.

Else:

    The speed is too slow.

    Search larger speeds.

Main insight:

As eating speed increases,
the required hours decrease.

This creates a monotonic
(true/false) condition:

Too slow   Fast enough



Binary search finds the
first valid speed.

Important details:

- Lower bound = 1
- Upper bound = max(piles)
- Store the current valid
  answer before searching left.

Time Complexity:

O(n log(maxPile))

Space Complexity:

O(1)
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());
        int ans = right;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            long long hours = 0;
            for (int pile : piles)
                hours += (pile + mid - 1) / mid;
            if (hours <= h) {
                ans = mid;
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        return ans;
    }
};
int main() {
    Solution sol;
    vector<int> piles = { 1,4,3,2 };
    cout << sol.minEatingSpeed(piles, 9);
    return 0;
}