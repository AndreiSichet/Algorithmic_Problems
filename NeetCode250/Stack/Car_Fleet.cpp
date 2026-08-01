/*
Car Fleet:

Compute the arrival time of every car:

    time = (target - position) / speed

Sort cars by position.

Process from the car closest to the
target toward the farthest.

If the current car takes longer to
reach the target than the fleet ahead,
it cannot catch that fleet.

It forms a new fleet.

Otherwise, it catches the fleet ahead
and becomes part of it.

Main insight:

Cars never pass each other.

Only the arrival time matters,
not the exact meeting position.

Traverse from right to left,
keeping the largest arrival time
seen so far.

Time Complexity:

O(n log n)

Space Complexity:

O(n)
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int carFleet(int target,vector<int>& position,vector<int>& speed) {
        vector<pair<int, double>> cars;
        for (int i = 0; i < position.size(); i++) {
            double time =(double)(target - position[i]) / speed[i];
            cars.push_back({ position[i], time });
        }
        sort(cars.begin(), cars.end());
        int fleets = 0;
        double currentTime = 0;
        for (int i = cars.size() - 1; i >= 0; i--) {
            if (cars[i].second > currentTime) {
                fleets++;
                currentTime = cars[i].second;
            }
        }
        return fleets;
    }
};
int main() {
    Solution sol;
    vector<int> pos1 = { 1,4 };
    vector<int> sp1 = { 3,2 };
    vector<int> pos2 = { 4,1,0,7 };
    vector<int> sp2 = { 2,2,1,1 };
    cout << sol.carFleet(10, pos1, sp1) << endl;
    cout << sol.carFleet(10, pos2, sp2) << endl;
    return 0;
}