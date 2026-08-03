/*
Sqrt(x):

Use binary search on the
range [1, x].

Maintain:

left
right
ans

While left <= right:

    Compute the middle.

    If mid * mid == x:
        return mid.

    If mid * mid < x:

        Store mid as the
        current best answer.

        Search the right half.

    Otherwise:

        Search the left half.

If no exact square root exists,
return the last valid answer.

Main insight:

Binary search the possible
square root instead of
checking every number.

Store the last value whose
square is less than or equal
to x, since the answer is
rounded down.

Important details:

- Use long long when computing
  mid * mid to avoid overflow.

- Compute mid as:

  left + (right - left) / 2

Time Complexity:

O(log x)

Space Complexity:

O(1)
*/
#include <iostream>
using namespace std;
class Solution {
public:
    int mySqrt(int x) {
        if (x == 0)
            return 0;
        int left = 1;
        int right = x;
        int ans = 0;
        while (left <= right) {
            long long mid = left + (right - left) / 2;
            if (mid * mid == x)
                return mid;
            if (mid * mid < x) {
                ans = mid;
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return ans;
    }
};
int main() {
    Solution sol;
    cout << sol.mySqrt(9) << endl;
    cout << sol.mySqrt(13) << endl;
    return 0;
}