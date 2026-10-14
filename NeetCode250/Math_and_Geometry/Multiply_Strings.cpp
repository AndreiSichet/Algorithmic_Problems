/*
ARRAY SIMULATION + CARRY - MULTIPLY STRINGS

Goal:
- Multiply two non-negative integers represented as strings.
- Return the product as a string without converting either input into an integer.
- Handle numbers larger than standard integer types can store.

Key idea:
- Simulate the multiplication algorithm used by hand.
- If num1 has m digits and num2 has n digits, their product has at most
  m + n digits.
- Create a result array of size m + n to store the product digits.
- Multiplying num1[i] by num2[j] contributes to positions i + j and i + j + 1.
- Store the current digit at i + j + 1 and propagate the carry to i + j.

Algorithm:
1. If either input is "0", return "0".
2. Create a vector result of size m + n, initialized to zero.
3. Traverse num1 and num2 from right to left using indices i and j:
   - Convert each character to its digit by subtracting '0'.
   - Calculate product = digit1 * digit2 + result[i + j + 1].
   - Store product % 10 at result[i + j + 1].
   - Add product / 10 to result[i + j].
4. Skip leading zeros in the result array.
5. Convert the remaining digits to a string and return it.

Why this works:
- Each pair of digits contributes to the corresponding decimal positions,
  just as in elementary multiplication.
- The existing value at result[i + j + 1] must be included because
  previous multiplications may already have contributed to that position.
- The remainder gives the digit for the current position, while integer
  division gives the carry for the position to its left.
- An array of size m + n is sufficient because the product cannot have
  more than m + n digits.

Important boundaries:
- If either input is "0", the product is "0".
- Do not convert the complete strings into integers.
- Use character - '0' to obtain each numeric digit.
- Remove leading zeros from the result, but ensure at least one digit remains.
- Each individual multiplication and accumulated carry fits in an int
  because each input digit is between 0 and 9.

Complexity:
- Time: O(m * n), because every pair of digits is multiplied once.
- Space: O(m + n) for the result array and output string.
*/

class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0")
            return "0";
        int m = num1.size();
        int n = num2.size();
        vector<int> result(m + n, 0);
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                int digit1 = num1[i] - '0';
                int digit2 = num2[j] - '0';
                int product = digit1 * digit2 + result[i + j + 1];
                result[i + j + 1] = product % 10;
                result[i + j] += product / 10;
            }
        }
        string answer;
        int i = 0;
        while (i < result.size() && result[i] == 0)
            i++;
        for (; i < result.size(); i++)
            answer += to_string(result[i]);

        return answer;
    }
};