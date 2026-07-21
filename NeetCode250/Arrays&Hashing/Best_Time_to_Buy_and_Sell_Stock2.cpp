/*
Best Time to Buy and Sell Stock II:

Use a greedy approach.

We can make unlimited transactions,
but we can hold at most one stock at a time.

If the price increases from one day to the next:

	prices[i] > prices[i - 1]

add the difference to the profit:

	profit += prices[i] - prices[i - 1];

If the price decreases, do nothing.

Why?
Every positive increase can be treated as a separate profit.

Example:
[1, 2, 3, 4]

Profit:
(2 - 1) + (3 - 2) + (4 - 3)
= 3

This is the same as:
4 - 1 = 3

Algorithm:
	1. Start profit at 0.
	2. Traverse the array from index 1.
	3. If today's price is greater than yesterday's,
	   add the difference to profit.
	4. Return profit.

Time Complexity: O(n)
Space Complexity: O(1)
*/
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int profit = 0;
		for (int i = 1; i < prices.size(); i++) {
			if (prices[i] > prices[i - 1]) {
				profit += prices[i] - prices[i - 1];
			}
		}
		return profit;
	}
};
int main() {
	Solution sol;
	vector<int> prices1 = { 7, 1, 5, 3, 6, 4 };
	cout << "Example 1: "
		<< sol.maxProfit(prices1)
		<< endl;
	vector<int> prices2 = { 1, 2, 3, 4, 5 };
	cout << "Example 2: "
		<< sol.maxProfit(prices2)
		<< endl;
	return 0;
}