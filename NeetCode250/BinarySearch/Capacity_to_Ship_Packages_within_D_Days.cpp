/*
Capacity to Ship Packages Within D Days:

Binary Search on the Answer.

Search for the minimum ship
capacity.

Search range:

left = maximum package weight

right = sum of all package weights

For each candidate capacity:

    Simulate loading packages
    in order.

    If adding the next package
    exceeds the capacity:

        Start a new day.

Count the number of days needed.

If daysNeeded <= days:

    The capacity works.

    Save it and try
    a smaller capacity.

Else:

    The capacity is too small.

    Search larger capacities.

Main insight:

As ship capacity increases,
the required number of days
never increases.

This creates a monotonic
(true/false) condition:

Too small      Works


Binary search finds the
smallest valid capacity.

Important details:

- Lower bound = largest package.
- Upper bound = sum of all packages.
- Packages must remain in order.
- Never split a package.

Time Complexity:

O(n log(sum(weights)))

Space Complexity:

O(1)
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int left = *max_element(weights.begin(), weights.end());
        int right = 0;
        for (int w : weights)
            right += w;
        int ans = right;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int daysNeeded = 1;
            int currentWeight = 0;
            for (int w : weights) {
                if (currentWeight + w > mid) {
                    daysNeeded++;
                    currentWeight = w;
                }
                else {
                    currentWeight += w;
                }
            }
            if (daysNeeded <= days) {
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
    vector<int> weights = { 2,4,6,1,3,10 };
    cout << sol.shipWithinDays(weights, 4);
    return 0;
}