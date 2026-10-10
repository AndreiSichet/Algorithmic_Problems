
/*
GREEDY + QUEUES - DOTA2 SENATE

Goal:
- Predict whether Radiant or Dire wins when both parties play optimally.
- Each senator bans one opposing senator before that senator can act.

Key idea:
- The order of senators matters because earlier senators act first.
- Use two queues to store the indices of active Radiant and Dire senators.
- The senator with the smaller index acts first and bans the opponent
  with the earliest upcoming turn.

Algorithm:
1. Create two queues:
   - radiant: indices of all 'R' senators.
   - dire: indices of all 'D' senators.

2. While both queues are non-empty:
   - Remove the front index from each queue.
   - The smaller index acts first and bans the other senator.
   - The winning senator survives and gets another turn next round.
   - Add the winner's index + n to their queue, representing their turn
     in the next round after all original indices.

3. When one queue becomes empty:
   - If radiant is non-empty, return "Radiant".
   - Otherwise, return "Dire".

Why add n?
- Original indices range from 0 to n-1.
- Adding n moves the surviving senator's next turn to the next round.
- Example: index 2 in a senate of size 5 gets its next turn at index 7.

Why the smaller index wins:
- It represents the senator who gets to act first in the current round.
- That senator can ban the opponent before the opponent gets a turn.

Mental model:
- Each queue represents the upcoming turns of one party.
- Compare the earliest active Radiant and Dire turns.
- The earlier one bans the other, then returns in the next round.

Complexity:
- Time: O(n), since each senator is banned at most once.
- Space: O(n) for the queues.
*/
class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> radiant, dire;
        int n = senate.size();
        for (int i = 0; i < n; i++) {
            if (senate[i] == 'R')
                radiant.push(i);
            else
                dire.push(i);
        }
        while (!radiant.empty() && !dire.empty()) {
            int r = radiant.front();
            radiant.pop();
            int d = dire.front();
            dire.pop();
            if (r < d)
                radiant.push(r + n);
            else
                dire.push(d + n);
        }
        return radiant.empty() ? "Dire" : "Radiant";
    }
};