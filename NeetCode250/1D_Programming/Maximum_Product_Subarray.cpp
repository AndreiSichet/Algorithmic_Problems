```cpp
/*
Problem:

Find the contiguous subarray with the largest product.

Key idea:

For every position, keep two values:

    maxProduct = largest product of a subarray
                 ending at the current position

    minProduct = smallest product of a subarray
                 ending at the current position

We need both because multiplying by a negative number
can turn the smallest negative product into the largest
positive product.

For every number, we have three possibilities:

    1. Start a new subarray:
           nums[i]

    2. Extend the previous maximum:
           maxProduct * nums[i]

    3. Extend the previous minimum:
           minProduct * nums[i]

Therefore:

    currentMax = max(
        nums[i],
        maxProduct * nums[i],
        minProduct * nums[i]
    )

    currentMin = min(
        nums[i],
        maxProduct * nums[i],
        minProduct * nums[i]
    )

Important:

Calculate currentMax and currentMin before updating
maxProduct and minProduct, because both calculations
need the previous values.

Time:
    O(n)

Space:
    O(1)
*/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxProduct = nums[0];
        int minProduct = nums[0];
        int answer = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            int currentMax = max({nums[i],maxProduct * nums[i],minProduct * nums[i]});
            int currentMin = min({nums[i],maxProduct * nums[i],minProduct * nums[i]});
            maxProduct = currentMax;
            minProduct = currentMin;
            answer = max(answer, maxProduct);
        }
        return answer;
    }
};