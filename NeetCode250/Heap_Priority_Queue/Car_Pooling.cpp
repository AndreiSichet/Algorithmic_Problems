/*
Car Pooling:

Each trip:
    [passengers, from, to]

At:
    from -> passengers get INTO the car
    to   -> passengers get OUT of the car

We need to make sure the number of passengers
never exceeds capacity.

Use a difference array:

    change[from] += passengers
    change[to]   -= passengers

Then scan locations from west to east.

At each location:
    passengers += change[location]

If passengers > capacity:
    return false

Otherwise:
    continue.

Why does this work?

Example:

    trip = [3, 2, 5]

    At location 2:
        +3 passengers

    At location 5:
        -3 passengers

So:
    change[2] += 3
    change[5] -= 3

We only care about pickup/dropoff locations.

Important:
    At the same location, passengers getting out
    are removed before/at the same point as new
    passengers getting in.

The difference array naturally handles this because
all changes at the same location are combined.

Time:
    O(n + MAX_LOCATION)

Space:
    O(MAX_LOCATION)

Since locations are small in this problem,
this is very efficient.
*/

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        // Locations are from 0 to 1000.
        vector<int> change(1001, 0);
        for (auto& trip : trips) {
            int passengers = trip[0];
            int from = trip[1];
            int to = trip[2];
            // Passengers enter.
            change[from] += passengers;
            // Passengers leave.
            change[to] -= passengers;
        }
        int passengers = 0;
        // Sweep from west to east.
        for (int location = 0; location <= 1000; location++) {
            passengers += change[location];
            if (passengers > capacity) {
                return false;
            }
        }
        return true;
    }
};