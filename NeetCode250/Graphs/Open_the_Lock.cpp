/*
Open The Lock:

Use BFS.

Think of every 4-digit lock combination as a node.

From every combination, we can make 8 moves:

    Increase wheel 1
    Decrease wheel 1
    Increase wheel 2
    Decrease wheel 2
    Increase wheel 3
    Decrease wheel 3
    Increase wheel 4
    Decrease wheel 4

Each move costs exactly 1 turn.

Therefore BFS gives the minimum number of turns.

Example:

    0000

Possible next states:

    1000
    9000
    0100
    0900
    0010
    0090
    0001
    0009

BFS explores:

    0 turns
    1 turn
    2 turns
    3 turns
    ...

So the first time we reach the target,
we have found the minimum number of turns.

Deadends:

    A deadend cannot be entered.

So we put all deadends into the visited set
before starting BFS.

This prevents BFS from entering them.

We also need a visited set because the lock can
return to a previous state.

For example:

    0000 -> 1000 -> 0000

Without visited, BFS could keep processing
the same states.

There are only:

    10 * 10 * 10 * 10 = 10000

possible lock combinations.

Wrap-around:

    9 -> 0
    0 -> 9

For increasing:

    (digit + 1) % 10

For decreasing:

    (digit + 9) % 10

Time:
    O(10000)

There are only 10000 possible states, and each
state has 8 neighbors.

Space:
    O(10000)

For the queue and visited set.
*/

class Solution {
public:
    string turn(string state, int index, int direction) {
        if (direction == 1) {
            state[index] = (state[index] - '0' + 1) % 10 + '0';
        }
        else {
            state[index] = (state[index] - '0' + 9) % 10 + '0';
        }
        return state;
    }
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> visited;
        for (string deadend : deadends) {
            visited.insert(deadend);
        }
        if (visited.count("0000")) {
            return -1;
        }
        queue<string> q;
        q.push("0000");
        visited.insert("0000");
        int turns = 0;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                string curr = q.front();
                q.pop();
                if (curr == target) {
                    return turns;
                }
                for (int j = 0; j < 4; j++) {
                    string next = turn(curr, j, 1);
                    if (!visited.count(next)) {
                        visited.insert(next);
                        q.push(next);
                    }
                    next = turn(curr, j, -1);
                    if (!visited.count(next)) {
                        visited.insert(next);
                        q.push(next);
                    }
                }
            }
            turns++;
        }
        return -1;
    }
};