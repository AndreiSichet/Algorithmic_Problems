/*
BINARY EXPONENTIATION - POW(X, N)

Goal:
- Calculate x raised to the power n without using built-in power functions.
- Handle both positive and negative exponents.
- Avoid O(|n|) repeated multiplications.

Key idea:
- Use binary exponentiation to reduce the number of multiplications.
- If the exponent is even, x^n = (x * x)^(n / 2).
- If the exponent is odd, multiply the result by x and reduce the exponent.
- For negative exponents, use x^(-n) = 1 / x^n.
- Convert n to a long long before negating it because INT_MIN cannot
  be safely negated using a 32-bit int.

Algorithm:
1. Convert n to a long long exponent.
2. If the exponent is negative:
   - Replace x with 1 / x.
   - Negate the exponent.
3. Initialize result = 1.0.
4. While the exponent is greater than 0:
   - If the exponent is odd:
       Multiply result by x.
   - Square x to represent the next power.
   - Divide the exponent by 2 using integer division.
5. Return result.

Why this works:
- Every time the exponent is halved, the number of required iterations
  is reduced significantly.
- When the exponent is odd, one factor of x is extracted and added
  to result, leaving an even exponent to process.
- Squaring x allows powers to grow exponentially:
  x, x^2, x^4, x^8, ...
- For negative exponents, taking the reciprocal converts the problem
  into an equivalent positive-exponent calculation.

Important boundaries:
- n = 0: return 1.0.
- n = 1: return x.
- n = -2: calculate (1 / x)^2.
- n = INT_MIN: use long long before negating n to avoid integer overflow.
- For x = 0 and n < 0, the mathematical result is undefined; standard
  problem constraints generally exclude this case.

Complexity:
- Time: O(log |n|), because the exponent is halved in each iteration.
- Space: O(1), because only a constant number of variables are used.
*/

class Solution {
public:
    double myPow(double x, int n) {
        long long exponent = n;
        if (exponent < 0) {
            x = 1.0 / x;
            exponent = -exponent;
        }
        double result = 1.0;
        while (exponent > 0) {
            if (exponent % 2 == 1)
                result *= x;
            x *= x;
            exponent /= 2;
        }
        return result;
    }
};