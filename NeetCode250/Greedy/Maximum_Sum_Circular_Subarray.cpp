/*
Problem:

Given a circular array nums, find the maximum possible sum
of a non-empty subarray.

Unlike a normal array, the end of the array connects back
to the beginning.

Example:

    nums = [5, -3, 5]

A normal maximum subarray would be:

    [5, -3, 5] = 7

But because the array is circular, we can take:

    [5] + [5]

which represents the circular subarray:

    [5, 5]

with sum:

    10


Key idea:

There are TWO possible types of maximum subarrays.


Case 1: The maximum subarray does NOT wrap around.

Then the problem is exactly the normal Maximum Subarray
problem.

We can find it using Kadane's Algorithm:

    maxNormal


Case 2: The maximum subarray DOES wrap around.

A wrapping subarray looks like:

    [elements at the end] + [elements at the beginning]


Instead of directly finding this wrapping subarray,
we can think about the part that is NOT included.

Example:

    nums = [5, -3, 5]

The best wrapping subarray is:

    [5] + [5]

The element we leave out is:

    [-3]

Therefore:

    wrapping sum
        = total sum - minimum subarray sum

In general:

    maxWrap = totalSum - minSubarray


Why?

If we remove the minimum-sum contiguous subarray from
the middle, the remaining elements form the maximum
wrapping subarray.


Therefore the answer is:

    max(
        maxNormal,
        totalSum - minSubarray
    )


We need THREE quantities:


1. Maximum normal subarray

Use Kadane's Algorithm:

    currentMax = max(nums[i], currentMax + nums[i])

    maxNormal = max(maxNormal, currentMax)


2. Minimum subarray

We can use the same idea, but reversed:

    currentMin = min(nums[i], currentMin + nums[i])

    minSubarray = min(minSubarray, currentMin)


3. Total sum

Calculate:

    totalSum += nums[i]


Important special case:

If ALL numbers are negative, then:

    minSubarray = totalSum

which would give:

    totalSum - minSubarray = 0

But the problem requires a NON-EMPTY subarray.

For example:

    nums = [-3, -2, -5]

The correct answer is:

    -2

not:

    0


Therefore:

    if (maxNormal < 0)
        return maxNormal;


This works because if every number is negative,
the maximum subarray is simply the largest individual
element.


Example:

    nums = [5, -3, 5]

Normal maximum:

    [5, -3, 5]
    sum = 7

Minimum subarray:

    [-3]
    sum = -3

Total:

    7

Wrapping maximum:

    total - minimum
    = 7 - (-3)
    = 10

Answer:

    max(7, 10)
    = 10


Mental model:

Normal case:

    [----------------]
         maxNormal


Circular case:

    [-----]     [-----]
              ^
              |
        minimum part removed

    maxWrap = totalSum - minSubarray


So the entire algorithm is:

    1. Find maximum subarray using Kadane.
    2. Find minimum subarray using Kadane.
    3. Find total sum.
    4. If all values are negative, return maxNormal.
    5. Otherwise return:

           max(maxNormal, totalSum - minSubarray)


Time:

    O(n)

We process the array once.


Space:

    O(1)

We only use a few variables.
*/

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int totalSum = 0;
        int currentMax = nums[0];
        int maxNormal = nums[0];
        int currentMin = nums[0];
        int minSubarray = nums[0];
        for (int i = 0; i < nums.size(); i++) {
            totalSum += nums[i];
            if (i > 0) {
                currentMax = max(nums[i], currentMax + nums[i]);
                maxNormal = max(maxNormal, currentMax);
                currentMin = min(nums[i], currentMin + nums[i]);
                minSubarray = min(minSubarray, currentMin);
            }
        }
        // All numbers are negative
        if (maxNormal < 0) {
            return maxNormal;
        }
        int maxWrap = totalSum - minSubarray;
        return max(maxNormal, maxWrap);
    }
};