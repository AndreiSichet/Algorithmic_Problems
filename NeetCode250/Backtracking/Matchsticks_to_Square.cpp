/*
Matchsticks to Square:

Use BACKTRACKING.

A square has 4 equal sides.

First calculate:

    total = sum of all matchsticks

If:

    total % 4 != 0

then a square is impossible.

The required length of every side is:

    side = total / 4

Now we need to assign every matchstick to one
of 4 sides.

Example:

    matchsticks = [1,1,2,2,2]

    total = 8
    side = 2

We need:

    side 0 = 2
    side 1 = 2
    side 2 = 2
    side 3 = 2

We can visualize the process as:

                    matchstick
                  /     |     |     \
                 /      |     |      \
              side 0  side 1 side 2  side 3

For each matchstick:

    1. Try putting it on side 0.
    2. Try putting it on side 1.
    3. Try putting it on side 2.
    4. Try putting it on side 3.

We cannot put it on a side if:

    sides[i] + matchstick > side

When all matchsticks have been assigned:

    index == matchsticks.size()

we check that all four sides equal side.

Example:

    [1,1,2,2,2]

    side = 2

One possible assignment:

        side 0: [2]
        side 1: [2]
        side 2: [2]
        side 3: [1,1]

All sides equal 2, so the answer is true.

Backtracking:

    Choose a side:
        sides[i] += matchstick

    Recursively place the next matchstick.

    Undo the choice:
        sides[i] -= matchstick

Sorting the matchsticks from largest to smallest
is an optimization.

Why?

Large matchsticks are harder to place.

If a large matchstick cannot fit anywhere,
we discover the failure early instead of exploring
many unnecessary possibilities.

Time:
    O(4^n)

Each matchstick can potentially be assigned
to one of 4 sides.

Space:
    O(n)

The recursion depth can reach n.
The four side lengths use O(1) additional space.

The result is only a boolean, so there is no
output storage.
*/

class Solution {
public:
    bool backtrack(vector<int>& matchsticks, int index, vector<int>& sides, int target) {
        if (index == matchsticks.size()) {
            return sides[0] == target &&
                sides[1] == target &&
                sides[2] == target &&
                sides[3] == target;
        }
        for (int i = 0; i < 4; i++) {
            if (sides[i] + matchsticks[index] > target) {
                continue;
            }
            sides[i] += matchsticks[index];
            if (backtrack(matchsticks, index + 1, sides, target)) {
                return true;
            }
            sides[i] -= matchsticks[index];
        }
        return false;
    }
    bool makesquare(vector<int>& matchsticks) {
        int total = 0;
        for (int stick : matchsticks) {
            total += stick;
        }
        if (total % 4 != 0) {
            return false;
        }
        int target = total / 4;
        sort(matchsticks.rbegin(), matchsticks.rend());
        vector<int> sides(4, 0);
        return backtrack(matchsticks, 0, sides, target);
    }
};