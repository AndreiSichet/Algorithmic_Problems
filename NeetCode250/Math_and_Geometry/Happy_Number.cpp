/*
CYCLE DETECTION - NON-CYCLICAL NUMBER

Goal:
- Determine whether repeatedly replacing a number with the sum of the
  squares of its digits eventually reaches 1.
- Return true if it reaches 1, otherwise return false if it enters a cycle.

Key idea:
- Each transformation produces a new number by summing the squares
  of the current number's digits.
- If the sequence reaches 1, the number is non-cyclical.
- Otherwise, the sequence eventually repeats a number and enters a cycle.
- Use Floyd's Cycle Detection Algorithm with slow and fast pointers
  to detect a cycle without storing previously seen numbers.

Algorithm:
1. Define a helper function getNext(n):
   - Extract each digit using n % 10.
   - Add the square of that digit to the sum.
   - Remove the digit using n /= 10.
   - Return the sum.
2. Initialize slow = n and fast = getNext(n).
3. While fast != 1 and slow != fast:
   - Move slow forward by one transformation.
   - Move fast forward by two transformations.
4. Return true if fast == 1; otherwise return false.

Why this works:
- If the sequence reaches 1, fast eventually reaches 1 and the algorithm
  returns true.
- If the sequence enters a cycle that does not contain 1, slow and fast
  eventually meet inside that cycle.
- Since fast moves twice as quickly as slow, they must meet if a cycle exists.
- Floyd's algorithm detects cycles without requiring a hash set.

Important boundaries:
- Check whether fast == 1 before checking for a cycle.
- A number can transform into itself or enter a longer cycle.
- For example, 19 -> 82 -> 68 -> 100 -> 1, so 19 returns true.
- For example, 2 -> 4 -> 16 -> 37 -> ... enters a cycle, so 2 returns false.

Complexity:
- Time: O(log n) per transformation, with a bounded number of distinct
  values before reaching 1 or entering a cycle; conventionally O(log n)
  for this problem's bounded digit-square sequence.
- Space: O(1), because only two pointers and a helper variable are used.
*/

class Solution {
public:
    int getNext(int n) {
        int sum = 0;
        while (n > 0) {
            int digit = n % 10;
            sum += digit * digit;
            n /= 10;
        }
        return sum;
    }

    bool isHappy(int n) {
        int slow = n;
        int fast = getNext(n);
        while (fast != 1 && slow != fast) {
            slow = getNext(slow);
            fast = getNext(getNext(fast));
        }
        return fast == 1;
    }
};