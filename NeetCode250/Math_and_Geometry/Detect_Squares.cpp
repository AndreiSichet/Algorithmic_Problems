/*
HASH MAP + GEOMETRY - DETECT SQUARES

Goal:
- Support adding points to a data structure, including duplicate points.
- Given a query point, count how many ways to choose three stored points
  that form an axis-aligned square with the query point.
- Every side must be parallel to the x-axis or y-axis.
- Duplicate points count as separate choices.

Key idea:
- Use a hash map to store the frequency of each point.
- Fix the query point as one corner of the square.
- The opposite corner must have a different x-coordinate and y-coordinate.
- For an axis-aligned square, the horizontal and vertical distances must
  be equal.
- Enumerate possible opposite corners and calculate the number of ways
  using the frequencies of the three required points.

Algorithm:
1. Maintain a hash map countMap:
   - Key: a point (x, y).
   - Value: the number of times that point has been added.
2. In add(point):
   - Increment countMap[point].
3. In count(point):
   - Initialize result = 0.
   - For every distinct stored point (x, y):
       a. Treat (x, y) as the opposite corner of the square.
       b. Calculate side = abs(x - queryX).
       c. Skip if side == 0 or abs(y - queryY) != side.
       d. The other two corners must be:
          (x, queryY) and (queryX, y).
       e. Multiply the frequencies of all three stored corners:
          countMap[(x, y)] *
          countMap[(x, queryY)] *
          countMap[(queryX, y)].
       f. Add this product to result.
   - Return result.

Why this works:
- Every valid square has exactly one corner diagonally opposite the query.
- Enumerating that opposite corner determines the side length and the
  other two corners uniquely.
- Equal horizontal and vertical distances guarantee that the shape is
  a square rather than a rectangle.
- Multiplying frequencies counts every possible selection of stored points,
  including duplicate points.
- Summing over all valid opposite corners counts every square exactly once.

Important boundaries:
- Skip points sharing the query's x-coordinate or having zero side length.
- Require abs(x - queryX) == abs(y - queryY).
- Duplicate points must increase the frequency, not be discarded.
- The query point itself does not need to be stored.
- Use long long for the accumulated answer if large counts are possible.

Complexity:
- Let U be the number of distinct stored points.
- add(): O(1) average time.
- count(): O(U) average time, since each distinct stored point is checked.
- Space: O(U) for the frequency map.
*/

class CountSquares {
private:
    map<pair<int, int>, int> countMap;

public:
    CountSquares() {}
    void add(vector<int> point) {
        countMap[{point[0], point[1]}]++;
    }
    int count(vector<int> point) {
        int queryX = point[0];
        int queryY = point[1];
        int result = 0;
        for (const auto& entry : countMap) {
            int x = entry.first.first;
            int y = entry.first.second;
            int side = abs(x - queryX);
            if (side == 0 || abs(y - queryY) != side)
                continue;
            result += entry.second * countMap[{x, queryY}] * countMap[{queryX, y}];
        }
        return result;
    }
};