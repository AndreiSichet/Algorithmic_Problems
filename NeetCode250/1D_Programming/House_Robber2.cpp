
/*
Problem:

Houses are arranged in a circle.

We cannot rob two adjacent houses.

The important difference from House Robber I is that
house 0 and house n - 1 are also adjacent.

Key idea:

We split the circular problem into two linear problems.

Case 1:
    Do not rob the first house.
    Rob from index 1 to n - 1.

Case 2:
    Do not rob the last house.
    Rob from index 0 to n - 2.

Then take the maximum of the two cases.

For the linear House Robber problem:

    skip current = prev1
    rob current  = prev2 + nums[i]

    current = max(skip current, rob current)

Time:
    O(n)

Space:
    O(1)
*/

class Solution {
public:

    int robRange(vector<int>& nums, int start, int end) {
        int prev2 = 0;
        int prev1 = 0;
        for (int i = start; i <= end; i++) {
            int current = max(prev1,prev2 + nums[i]);
            prev2 = prev1;
            prev1 = current;
        }
        return prev1;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return nums[0];
        }
        int excludeFirst = robRange(nums, 1, n - 1);
        int excludeLast = robRange(nums, 0, n - 2);
        return max(excludeFirst, excludeLast);
    }
};