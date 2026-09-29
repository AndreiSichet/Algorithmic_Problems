
/*
Problem:
Alice and Bob take turns taking a pile from either the beginning
or the end of the row. There is an even number of piles, and Alice
starts.

Key idea:
This problem does NOT need DP.

Because there are an even number of piles, Alice can force herself
to take either all the odd-indexed piles or all the even-indexed piles.

The total number of stones is odd, so:

    odd-position sum != even-position sum

Therefore, one of the two groups is guaranteed to have more stones.

Alice can choose the better parity and force herself to collect
that group.

So Alice always wins.

Example:

    piles = [5, 3, 4, 5]

Odd positions:
    5 + 4 = 9

Even positions:
    3 + 5 = 8

Alice can force the odd-position piles, so she wins.

Complexity:
Time:  O(1)
Space: O(1)
*/
class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        return true;
    }
};