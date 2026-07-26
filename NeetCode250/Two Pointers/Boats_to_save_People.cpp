/*
Boats to Save People:

Sort the array.

Use two pointers:
    left  -> lightest person
    right -> heaviest person

Try to put the heaviest person
with the lightest person.

If:
    people[left] + people[right] <= limit

they can share a boat:
    left++

The heaviest person is always placed:
    right--

If they cannot fit together,
the heaviest person must go alone.

Each iteration uses one boat.

Time Complexity: O(n log n)
    due to sorting

Space Complexity: O(1) extra space
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int left = 0;
        int right = people.size() - 1;
        int boats = 0;
        while (left <= right) {
            if (people[left] + people[right] <= limit) {
                left++;
            }
            right--;
            boats++;
        }
        return boats;
    }
};
int main() {
    Solution sol;
    vector<int> people1 = { 5, 1, 4, 2 };
    int limit1 = 6;
    cout << "Example 1: "<< sol.numRescueBoats(people1, limit1)<< endl;
    vector<int> people2 = { 1, 3, 2, 3, 2 };
    int limit2 = 3;
    cout << "Example 2: "<< sol.numRescueBoats(people2, limit2)<< endl;
    return 0;
}