/*
Problem:

Given an array of integers nums, find the contiguous subarray
with the largest sum.

The subarray must:

    1. Be contiguous
    2. Be non-empty

Return the maximum possible sum.


Key idea:

Use Dynamic Programming with a greedy idea.

We keep track of the maximum sum of a subarray that
ENDS at the current position.

Define:

    current = maximum subarray sum ending at the current element.

At every element, we have two choices:

    1. Start a new subarray from the current element.

    2. Extend the previous subarray by adding the current element.


Therefore:

    current = max(nums[i], current + nums[i])


Why?

If the previous sum is negative, keeping it would only
make the current subarray smaller.

For example:

    current = -5
    nums[i] = 3

Then:

    current + nums[i] = -2

while:

    nums[i] = 3

So it is better to start a new subarray:

    [3]


However, if:

    current = 5
    nums[i] = 3

then:

    current + nums[i] = 8

which is better than starting over with 3.

So we extend the existing subarray.


We also need another variable:

    best

which stores the maximum subarray sum found anywhere
in the array so far.

At every position:

    current = max(nums[i], current + nums[i])

    best = max(best, current)


Example:

    nums = [-2, 1, -3, 4, -1, 2, 1, -5, 4]


Start:

    current = -2
    best = -2


Process 1:

    current = max(1, -2 + 1)
            = 1

    best = 1


Process -3:

    current = max(-3, 1 - 3)
            = -2

    best = 1


Process 4:

    current = max(4, -2 + 4)
            = 4

    best = 4


Process -1:

    current = max(-1, 4 - 1)
            = 3

    best = 4


Process 2:

    current = max(2, 3 + 2)
            = 5

    best = 5


Process 1:

    current = max(1, 5 + 1)
            = 6

    best = 6


The maximum subarray is:

    [4, -1, 2, 1]

with sum:

    6


Important:

We initialize both variables with nums[0]:

    current = nums[0]
    best = nums[0]

This is important because the subarray must be non-empty.

For example:

    nums = [-5, -2, -8]

The answer is:

    -2

not 0.

If we initialized best to 0, we would incorrectly return 0.


Mental model:

At every element, ask:

    "Should I continue the previous subarray,
     or should I start a new one here?"

    Continue:
        current + nums[i]

    Start new:
        nums[i]

Choose:

    max(nums[i], current + nums[i])


Then ask:

    "Is this the best subarray I have seen so far?"

    best = max(best, current)


This is commonly known as Kadane's Algorithm.


Time:

    O(n)

We process every element once.


Space:

    O(1)

We only use two variables.
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int current = nums[0];
        int best = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            current = max(nums[i], current + nums[i]);
            best = max(best, current);
        }
        return best;
    }
};  