/*
Problem:

Find the length of the longest subarray where the comparison
sign alternates:

    < > < > ...

or:

    > < > < ...


Key idea:

Use two states:

    up   = longest turbulent subarray ending at i where
           arr[i-1] < arr[i]

    down = longest turbulent subarray ending at i where
           arr[i-1] > arr[i]


If arr[i-1] < arr[i]:

    up = down + 1

The previous comparison must have been decreasing.


If arr[i-1] > arr[i]:

    down = up + 1

The previous comparison must have been increasing.


If arr[i-1] == arr[i]:

    up = 1
    down = 1

Equal elements break the turbulent pattern.


Example:

    [9, 4, 2, 10]

    9 > 4
        down = 2

    4 > 2
        same direction, start new:
        down = 2

    2 < 10
        opposite direction:
        up = down + 1 = 3


Mental model:

    up   -> down
    down -> up

The comparison must always flip.


Time:
    O(n)

Space:
    O(1)
*/

class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int up = 1;
        int down = 1;
        int answer = 1;
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i - 1] < arr[i]) {
                up = down + 1;
                down = 1;
            }
            else if (arr[i - 1] > arr[i]) {
                down = up + 1;
                up = 1;
            }
            else {
                up = 1;
                down = 1;
            }
            answer = max(answer, max(up, down));
        }
        return answer;
    }
};