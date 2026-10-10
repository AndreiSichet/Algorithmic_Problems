
/*
GREEDY - MERGE TRIPLETS TO FORM TARGET

Goal:
- Determine whether we can form target = [x, y, z] by taking the
  coordinate-wise maximum of selected triplets.

Key observations:
- The merge operation only increases values because it uses max().
- If any coordinate of a triplet exceeds the corresponding target value,
  that triplet cannot be used: we cannot decrease that coordinate later.
- Therefore, discard every triplet [a,b,c] where:
    a > x || b > y || c > z

Greedy idea:
- Among the remaining triplets, find whether we can obtain each target
  coordinate exactly.
- A valid triplet can contribute to one or more target coordinates.
- We do not need one triplet to equal target by itself; different valid
  triplets can provide x, y, and z.

Algorithm:
1. Initialize three flags: gotX, gotY, gotZ = false.
2. Iterate through every triplet [a,b,c].
3. Skip it if any coordinate exceeds its target coordinate.
4. Otherwise, mark each coordinate it matches:
     if a == x, gotX = true
     if b == y, gotY = true
     if c == z, gotZ = true
5. Return true only if all three flags are true.

Why this works:
- Invalid triplets cannot be used because max() would preserve an
  excessive coordinate.
- Every valid triplet has coordinates <= target.
- If valid triplets collectively contain x, y, and z in their respective
  coordinates, merging them produces exactly target.
- If any target coordinate is never matched, it cannot be created by max().

Complexity:
- Time: O(n), where n is the number of triplets.
- Extra space: O(1).
*/
class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        bool gotX = false;
        bool gotY = false;
        bool gotZ = false;
        for (auto& t : triplets) {
            if (t[0] > target[0] || t[1] > target[1] || t[2] > target[2])
                continue;
            if (t[0] == target[0]) gotX = true;
            if (t[1] == target[1]) gotY = true;
            if (t[2] == target[2]) gotZ = true;
        }
        return gotX && gotY && gotZ;
    }
};