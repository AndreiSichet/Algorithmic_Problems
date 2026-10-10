
/*
GREEDY + ORDERED MAP - HAND OF STRAIGHTS

Goal:
- Split all cards into groups of groupSize consecutive values.
- Every card must be used exactly once.

Key observations:
- If hand.size() is not divisible by groupSize, return false.
- Always start the next group with the smallest remaining card.
- If the smallest remaining card is x, we must form:
    x, x+1, x+2, ..., x+groupSize-1
- Use a frequency map to track how many copies of each card remain.
- An ordered map processes card values from smallest to largest.

Algorithm:
1. Count each card's frequency in an ordered map.
2. Iterate through the map from smallest to largest.
3. For each value x with remaining frequency count:
   - We must start `count` groups at x.
   - For every value from x to x+groupSize-1:
       - Check that at least `count` copies exist.
       - If not, return false.
       - Subtract `count` copies.
4. If all required cards are available, return true.

Why subtract `count`?
- If x appears 3 times, all 3 copies must begin separate groups.
- Each of those groups needs one copy of x+1, x+2, and so on.
- Therefore, every consecutive value must have at least 3 copies.

Why greedy works:
- The smallest remaining card cannot be placed after another card,
  because no smaller unused card can precede it.
- It must begin a group, so we greedily build groups from that value.
- If any required consecutive card is missing, no valid arrangement exists.

Complexity:
- Time: O(n log n + n * groupSize) in the straightforward implementation.
- Space: O(n) for the frequency map.
*/
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0)
            return false;
        map<int, int> count;
        for (int card : hand)
            count[card]++;
        for (auto& [card, freq] : count) {
            if (freq == 0)
                continue;
            int needed = freq;
            for (int value = card; value < card + groupSize; value++) {
                if (count[value] < needed)
                    return false;
                count[value] -= needed;
            }
        }
        return true;
    }
};