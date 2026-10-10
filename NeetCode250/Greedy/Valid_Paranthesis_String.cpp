
/*
GREEDY - VALID PARENTHESIS STRING

Goal:
- Check whether s can become a valid parenthesis string.
- '*' can represent '(', ')', or an empty string.

Key idea:
- Instead of deciding what each '*' represents immediately, track the
  RANGE of possible open-parenthesis counts.

Variables:
- `low` = minimum possible number of unmatched '('.
- `high` = maximum possible number of unmatched '('.

Algorithm:
1. Start with low = 0 and high = 0.

2. Process each character:
   If s[i] == '(':
     - Both bounds increase by 1.

   If s[i] == ')':
     - Both bounds decrease by 1.

   If s[i] == '*':
     - It can act as ')', '(', or empty.
     - Decrease low by 1 (treat '*' as ')').
     - Increase high by 1 (treat '*' as '(').

3. If high < 0:
   - Even treating every '*' as '(' cannot prevent too many closing
     parentheses.
   - Return false.

4. If low < 0:
   - Clamp low to 0 because we cannot have fewer than zero unmatched
     opening parentheses. The '*' can instead be treated as empty.

5. After processing the string:
   - If low == 0, a valid interpretation exists.
   - If low > 0, every interpretation leaves unmatched '('.
   - Return low == 0.

Why this works:
- `low` and `high` represent the range of possible unmatched opening
  parentheses across all valid interpretations of the prefix.
- If high becomes negative, no interpretation can be valid.
- Clamping low to zero removes impossible negative counts.
- A valid string must finish with exactly zero unmatched '('.

Example:
s = "(*))"

Start: low=0, high=0
'(' : low=1, high=1
'*' : low=0, high=2
')' : low=0, high=1
')' : low=0, high=0

low == 0 -> true.

Mental model:
- Each character changes the range of possible open-parenthesis counts.
- `high` checks whether validity is still possible.
- `low` checks whether we can finish with zero unmatched opening parentheses.

Complexity:
- Time: O(n)
- Extra space: O(1)
*/
class Solution {
public:
    bool checkValidString(string s) {
        int low = 0;
        int high = 0;
        for (char c : s) {
            if (c == '(') {
                low++;
                high++;
            }
            else if (c == ')') {
                low--;
                high--;
            }
            else {
                low--;
                high++;
            }
            if (high < 0)
                return false;
            low = max(low, 0);
        }
        return low == 0;
    }
};