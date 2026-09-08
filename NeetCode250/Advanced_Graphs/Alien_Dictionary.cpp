/*
Alien Dictionary:

This is a Topological Sort problem.

We need to figure out the ordering of the letters.

Step 1:
Compare every pair of neighboring words.

For example:

```
"wrt"
"wrf"
```

The first two characters are the same:

```
w == w
r == r
```

The first different characters are:

```
t and f
```

Therefore:

```
t comes before f
```

So we create the edge:

```
t -> f
```

Step 2:
Build a graph containing these ordering rules.

Step 3:
Use topological sort to find an ordering of the letters.

We use indegree:

```
indegree[x] = number of letters that must come before x
```

A letter with indegree 0 has no requirements,
so it can be placed next.

Important:

We must include every unique letter that appears in words,
even if that letter has no edges.

Invalid prefix case:

```
["abc", "ab"]
```

This is invalid because "ab" is a prefix of "abc",
but the longer word appears first.

If:

```
words[i] starts with words[i + 1]
```

and words[i] is longer,

return "".

Cycle case:

If topological sort cannot process every unique letter,
there is a cycle.

Example:

```
a -> b
b -> a
```

No valid ordering exists, so return "".

Important detail:

When comparing two words, ONLY the first different
character gives us an ordering rule.

Do not compare all different characters.

Complexity:

Let C be the total number of characters in all words.

Building the graph:
O(C)

Topological sort:
O(26 + edges)

Since there are only 26 possible letters,
this is effectively O(C).

Space:
O(26)
*/

class Solution {
public:
    string alienOrder(vector<string>& words) {
        unordered_map<char, vector<char>> graph;
        unordered_map<char, int> indegree;
            for (string& word : words) {
                for (char c : word) {
                    indegree[c] = 0;
                }
            }
        for (int i = 0; i + 1 < words.size(); i++) {
            string& first = words[i];
            string& second = words[i + 1];
            int len = min(first.size(), second.size());
            bool foundDifference = false;
            for (int j = 0; j < len; j++) {
                if (first[j] != second[j]) {
                    char a = first[j];
                    char b = second[j];
                    bool exists = false;
                    for (char next : graph[a]) {
                        if (next == b) {
                            exists = true;
                            break;
                        }
                    }
                    if (!exists) {
                        graph[a].push_back(b);
                        indegree[b]++;
                    }
                    foundDifference = true;
                    break;
                }
            }
            if (!foundDifference && first.size() > second.size()) {
                return "";
            }
        }
        queue<char> q;
        for (auto& [letter, degree] : indegree) {
            if (degree == 0) {
                q.push(letter);
            }
        }
        string result;
        while (!q.empty()) {
            char curr = q.front();
            q.pop();
            result.push_back(curr);
            for (char next : graph[curr]) {
                indegree[next]--;
                if (indegree[next] == 0) {
                    q.push(next);
                }
            }
        }
        if (result.size() != indegree.size()) {
            return "";
        }
        return result;
    }
};