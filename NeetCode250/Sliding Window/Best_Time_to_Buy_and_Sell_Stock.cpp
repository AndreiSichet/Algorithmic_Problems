/*
Best Time to Buy and Sell Stock:

Only one transaction is allowed.

Keep track of:

    minPrice  -> lowest price seen so far
    maxProfit -> maximum profit found

For each price:

1. Update minPrice if the current price is lower.

2. Calculate:
       profit = currentPrice - minPrice

3. Update maxProfit.

Main insight:

At each day, assume we sell today.
The best buying day is simply the lowest price
seen before today.

Time Complexity: O(n)
Space Complexity: O(1)
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = prices[0];
        int maxProfit = 0;
        for (int i = 1; i < prices.size(); i++) {
            minPrice = min(minPrice, prices[i]);
            int profit = prices[i] - minPrice;
            maxProfit = max(maxProfit, profit);
        }
        return maxProfit;
    }
};
int main() {
    Solution sol;
    vector<int> prices1 = { 10,1,5,6,7,1 };
    vector<int> prices2 = { 10,8,7,5,2 };
    cout << "Example 1: " << sol.maxProfit(prices1) << endl;
    cout << "Example 2: "  << sol.maxProfit(prices2)  << endl;
    return 0;
}