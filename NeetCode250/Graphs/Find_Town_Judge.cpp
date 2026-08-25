/*
Find the Town Judge:

Use one score array.

For every trust relationship:

    a trusts b

Person a cannot be the judge because the judge
trusts nobody.

So:

    score[a]--

Person b is trusted by someone.

So:

    score[b]++

For the town judge:

    trusts nobody
        -> loses 0

    trusted by everyone else
        -> gains n - 1

Therefore:

    score[judge] = n - 1

Example:

    n = 3

    trust = [[1,3],[2,3]]

Start:

    score = [0,0,0,0]

After [1,3]:

    score[1]--
    score[3]++

After [2,3]:

    score[2]--
    score[3]++

Result:

    score[1] = -1
    score[2] = -1
    score[3] = 2

Since:

    n - 1 = 2

person 3 is the judge.

Why not just find who is trusted by everyone?

Because the judge must also trust nobody.

Example:

    n = 3
    trust = [[1,3],[2,3],[3,1]]

Person 3 is trusted by everyone else,
but person 3 also trusts person 1.

The score catches this:

    score[3] = 1

But the required score is:

    n - 1 = 2

So person 3 is not the judge.

Time:
    O(n + trust.size())

Space:
    O(n)
*/

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> score(n + 1, 0);
        for (auto& relation : trust) {
            int a = relation[0];
            int b = relation[1];
            score[a]--;
            score[b]++;
        }
        for (int person = 1; person <= n; person++) {
            if (score[person] == n - 1) {
                return person;
            }
        }
        return -1;
    }
};