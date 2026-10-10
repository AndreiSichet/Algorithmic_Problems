
/*
GREEDY - CANDY

Goal:
- Give each child at least one candy.
- A child with a higher rating than an adjacent child must receive
  more candies than that neighbor.
- Minimize the total number of candies.

Key idea:
- Each child must satisfy constraints from both the left and right neighbors.
- One left-to-right pass handles increasing ratings.
- One right-to-left pass handles decreasing ratings.
- The number of candies for each child must satisfy both constraints.

Algorithm:
1. Give every child 1 candy initially.

2. Left-to-right pass:
   - If ratings[i] > ratings[i-1], child i needs more candies than
     the left neighbor.
   - Set candies[i] = candies[i-1] + 1.
   - Otherwise, keep candies[i] = 1.

3. Right-to-left pass:
   - If ratings[i] > ratings[i+1], child i needs more candies than
     the right neighbor.
   - Update:
       candies[i] = max(candies[i], candies[i+1] + 1)
   - Use max because the left-to-right pass may already have assigned
     more candies to satisfy the left neighbor.

4. Sum all candy values and return the total.

Why two passes work:
- The first pass guarantees every increasing pair satisfies the rule
  from left to right.
- The second pass guarantees every decreasing pair satisfies the rule
  from right to left.
- Taking max preserves the constraints established by the first pass.
- Starting with 1 candy and only increasing when required gives the
  minimum valid distribution.

Example:
ratings = [1, 0, 2]

Initial:  [1, 1, 1]
Left pass:[1, 1, 2]
Right pass:[2, 1, 2]

Total = 5.

Complexity:
- Time: O(n)
- Extra space: O(n) for the candies array.
*/
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> candies(n, 1);
        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1])
                candies[i] = candies[i - 1] + 1;
        }
        for (int i = n - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1])
                candies[i] = max(candies[i], candies[i + 1] + 1);
        }
        int total = 0;
        for (int c : candies)
            total += c;
        return total;
    }
};