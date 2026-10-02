/*
Problem:

You run a lemonade stand where each lemonade costs $5.

Customers pay with:

    $5
    $10
    $20

For every customer, you must give the correct change.

Initially:

    $5 bills = 0
    $10 bills = 0
    $20 bills = 0

Return true if you can serve every customer in order.
Otherwise, return false.


Key idea:

Use a Greedy approach.

We process the customers from left to right.

For every bill, give the required change using the bills
we currently have.

The important greedy choice is:

    When giving $15 change for a $20 bill,
    use one $10 bill + one $5 bill
    whenever possible.

Why?

Because $5 bills are more useful than $10 bills.

A $5 bill can be used as change for:

    $10 -> needs $5
    $20 -> needs $15

A $10 bill can only help with:

    $20 -> needs $15

Therefore, we should preserve $5 bills whenever possible.


Case 1: Customer pays with $5

No change is needed.

We simply receive a $5 bill.

    five++

Case 2: Customer pays with $10

The customer needs:

    $10 - $5 = $5

Therefore, we need one $5 bill.

If we have one:

    five--
    ten++

Otherwise:

    return false


Case 3: Customer pays with $20

The customer needs:

    $20 - $5 = $15

There are two possible ways to give $15:

    1. One $10 + one $5
    2. Three $5 bills

Greedy choice:

    Prefer $10 + $5

because this preserves two $5 bills for future customers.

So:

    if ten > 0 && five > 0:

        ten--
        five--

    else if five >= 3:

        five -= 3

    else:

        return false


Why do we not keep $10 bills when possible?

Suppose we have:

    five = 1
    ten = 1

and a customer pays $20.

We could theoretically use three $5 bills, but we don't have
three $5 bills.

Using:

    $10 + $5

is the only possible solution.

More importantly, using $10 + $5 instead of $5 + $5 + $5
preserves two $5 bills.

Those $5 bills are needed to give change for future $10 bills.


Example:

    bills = [5, 5, 5, 10, 20]

Process:

    5:
        five = 1

    5:
        five = 2

    5:
        five = 3

    10:
        give $5
        five = 2
        ten = 1

    20:
        give $10 + $5
        five = 1
        ten = 0

Every customer can be served.

Answer:

    true


Mental model:

    $5:
        collect it

    $10:
        give one $5

    $20:
        give $10 + $5 if possible
        otherwise give $5 + $5 + $5

Always prefer:

    $10 + $5

over:

    $5 + $5 + $5

because $5 bills are more flexible.


Time:

    O(n)

We process every customer exactly once.


Space:

    O(1)

We only store the number of $5 and $10 bills.
There is no need to track $20 bills because they are never
useful as change.
*/

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0;
        int ten = 0;
        for (int bill : bills) {
            // Customer pays with $5
            if (bill == 5) {
                five++;
            }
            // Customer pays with $10
            else if (bill == 10) {
                if (five == 0) {
                    return false;
                }
                five--;
                ten++;
            }
            // Customer pays with $20
            else {
                // Prefer $10 + $5
                if (ten > 0 && five > 0) {
                    ten--;
                    five--;
                }
                // Otherwise use three $5 bills
                else if (five >= 3) {
                    five -= 3;
                }
                else {
                    return false;
                }
            }
        }
        return true;
    }
};