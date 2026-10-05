
/*
GREEDY - GAS STATION

Goal:
- Find the unique station from which we can complete the full circle.
- At station i:
    gas[i] - cost[i] = net gas gained/lost after traveling to i+1.

Key idea:
- First check whether there is enough total gas to complete the circuit.
- If:
    sum(gas) < sum(cost)
  then completing the circuit is impossible -> return -1.

Greedy observation:
- Let `tank` be the gas available after reaching the current station.
- Start with candidate = 0 and tank = 0.
- If tank becomes negative at station i:
    candidate cannot be a valid starting station.
- More importantly, NO station between the current candidate and i can
  be a valid start either.

Why?
- Starting from candidate gives us the most gas possible among those
  stations by the time we reach i.
- If even candidate cannot reach i+1, any station after candidate has
  had fewer opportunities to accumulate gas.
- Therefore we can skip all of them and set:
    candidate = i + 1
    tank = 0

Algorithm:
1. Calculate the total gas balance:
     total += gas[i] - cost[i]

2. If total < 0:
     return -1
   There is not enough gas in the entire circuit.

3. Try stations greedily:
     tank += gas[i] - cost[i]

4. If tank < 0:
     The current candidate fails at i.
     Set candidate = i + 1.
     Reset tank = 0.

5. If total >= 0, the remaining candidate is guaranteed to work.

Example:
gas  = [1,2,3,4,5]
cost = [3,4,5,1,2]

Net:
[-2,-2,-2,+3,+3]

Start at 0:
tank = -2 -> fail
candidate = 1

Start at 1:
tank = -2 -> fail
candidate = 2

Start at 2:
tank = -2 -> fail
candidate = 3

Start at 3:
tank = +3
then +3
then +1
then +2
then +1

So station 3 works.

Mental model:
- `tank` tells us whether the current candidate can survive.
- When `tank < 0`, the candidate and every station before the failure
  point can be discarded.
- `total >= 0` guarantees that some station must work.
- The final candidate is therefore the answer.

Complexity:
- Time: O(n)
- Space: O(1)
*/
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total = 0;
        int tank = 0;
        int candidate = 0;
        for (int i = 0; i < gas.size(); i++) {
            int net = gas[i] - cost[i];
            total += net;
            tank += net;
            if (tank < 0) {
                candidate = i + 1;
                tank = 0;
            }
        }
        if (total < 0)
            return -1;
        return candidate;
    }
};