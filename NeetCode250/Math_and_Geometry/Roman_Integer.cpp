/*
GREEDY + LOOKAHEAD - ROMAN TO INTEGER

Goal:
- Convert a Roman numeral string into its integer value.
- Handle both additive symbols and subtractive pairs.

Key idea:
- Normally, Roman numeral values are added from left to right.
- If a symbol has a smaller value than the symbol immediately after it,
  subtract its value instead of adding it.
- Otherwise, add its value normally.
- This handles all six subtractive combinations without checking each pair
  separately.

Algorithm:
1. Create a helper function that maps each Roman symbol to its integer value.
2. Initialize result = 0.
3. Traverse the string from left to right.
4. For each symbol s[i]:
   - If i + 1 exists and value(s[i]) < value(s[i + 1]):
       Subtract value(s[i]) from result.
   - Otherwise:
       Add value(s[i]) to result.
5. Return result.

Why this works:
- Symbols followed by an equal or smaller value contribute positively.
- A smaller symbol before a larger one represents subtraction.
  For example, IV = -1 + 5 = 4.
- Processing each symbol exactly once accounts for every additive
  symbol and every subtractive pair.

Important boundaries:
- Check that i + 1 < s.size() before accessing the next symbol.
- Use strict inequality: subtract only when the current value is smaller.
- Examples:
  - III = 1 + 1 + 1 = 3
  - IV = -1 + 5 = 4
  - MCMXCIV = 1000 - 100 + 1000 - 10 + 100 - 1 + 5 = 1994

Complexity:
- Time: O(n), where n is the length of the string.
- Space: O(1), because only a constant amount of extra memory is used.
*/

class Solution {
public:
    int getValue(char c) {
        switch (c) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        }
        return 0;
    }
    int romanToInt(string s) {
        int result = 0;
        for (int i = 0; i < s.size(); i++) {
            int current = getValue(s[i]);
            if (i + 1 < s.size() && current < getValue(s[i + 1]))
                result -= current;
            else
                result += current;
        }
        return result;
    }
};