/*
Guess Number Higher or Lower:

Use binary search on the
range [1, n].

Maintain:

left = 1
right = n

While left <= right:

    Compute the middle.

    Call guess(mid).

    If guess(mid) == 0:
        return mid.

    If guess(mid) == -1:
        The guess is too high.
        Search the left half.

    If guess(mid) == 1:
        The guess is too low.
        Search the right half.

Main insight:

The API tells whether the
target is higher or lower.

This allows us to eliminate
half of the search space
after every guess.

Important details:

- Search between 1 and n.
- Use:

  mid = left + (right - left) / 2

  to avoid integer overflow.

Time Complexity:

O(log n)

Space Complexity:

O(1)
*/
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	int guessNumber(int n) {
        int left = 1;
        int right = n;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int res = guess(mid);
            if (res == 0) {
                return mid;
            }
            if (res == -1) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        return -1;
	}
};