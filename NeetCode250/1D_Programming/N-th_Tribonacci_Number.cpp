
/*
Problem:

Return the nth Tribonacci number.

The sequence is:

T0 = 0
T1 = 1
T2 = 1

For n >= 3:

Tn = Tn-1 + Tn-2 + Tn-3

Key idea:

To calculate the next Tribonacci number,
we only need the previous three values.

We keep:

a = Tn-3
b = Tn-2
c = Tn-1

Then:

next = a + b + c

After calculating next, shift the values:

a = b
b = c
c = next

Time:
    O(n)

Space:
    O(1)
*/

class Solution {
public:
    int tribonacci(int n) {
        if (n == 0) {
            return 0;
        }
        if (n == 1 || n == 2) {
            return 1;
        }
        int a = 0;
        int b = 1;
        int c = 1;
        for (int i = 3; i <= n; i++) {
            int next = a + b + c;
            a = b;
            b = c;
            c = next;
        }
        return c;
    }
};
