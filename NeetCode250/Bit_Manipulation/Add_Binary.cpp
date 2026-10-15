/*
SIMULATION + CARRY - ADD BINARY

Goal:
- Add two binary numbers represented as strings.
- Return their sum as a binary string.
- Do not convert the strings into integers, since they may be too large.

Key idea:
- Simulate binary addition from right to left, just like decimal addition.
- Each position contains two bits and a possible carry from the previous
  position.
- The current sum determines the output bit and the next carry:
  - outputBit = sum % 2
  - carry = sum / 2
- Continue until both strings and the carry have been fully processed.

Algorithm:
1. Initialize pointers i and j to the last characters of a and b.
2. Initialize carry = 0 and an empty result string.
3. While i >= 0, j >= 0, or carry != 0:
   - Initialize sum = carry.
   - If i >= 0, add a[i] - '0' to sum and decrement i.
   - If j >= 0, add b[j] - '0' to sum and decrement j.
   - Append sum % 2 to result.
   - Update carry = sum / 2.
4. Reverse result because the bits were generated from least significant
   to most significant.
5. Return result.

Why this works:
- Binary addition follows the same carry principle as decimal addition,
  but each position can only contain 0 or 1.
- The possible sum at each position is 0, 1, 2, or 3.
- Taking sum % 2 gives the correct result bit.
- Taking sum / 2 gives the carry to the next position.
- Processing every position and the final carry ensures no bits are lost.

Important boundaries:
- If one string is shorter, treat its missing bits as 0.
- The loop must continue while carry != 0, even if both strings are finished.
- For example, "11" + "1" = "100".
- Do not convert the complete strings into integer types.

Complexity:
- Time: O(max(n, m)), where n and m are the lengths of a and b.
- Space: O(max(n, m)) for the result string.
*/

class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size() - 1;
        int j = b.size() - 1;
        int carry = 0;
        string result;
        while (i >= 0 || j >= 0 || carry != 0) {
            int sum = carry;
            if (i >= 0)
                sum += a[i--] - '0';
            if (j >= 0)
                sum += b[j--] - '0';
            result += char('0' + sum % 2);
            carry = sum / 2;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};