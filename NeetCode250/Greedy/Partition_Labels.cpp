
/*
GREEDY - PARTITION LABELS

Goal:
- Split s into the maximum number of contiguous substrings.
- Each character must appear in at most one substring.

Key idea:
- A partition cannot end at index i if any character inside it appears
  again later in the string.
- Precompute the last occurrence of every character.
- Each partition must extend at least to the last occurrence of every
  character encountered inside it.

Algorithm:
1. Build an array `last` where last[c] is the final index of character c.
2. Scan s from left to right, tracking:
   - `start`: beginning of the current partition.
   - `end`: farthest last occurrence required by characters seen so far.
3. For each index i:
   - Extend the partition boundary:
       end = max(end, last[s[i]])
   - If i == end, every character in this partition has its last
     occurrence within the partition.
     Therefore, close it and record its size:
       i - start + 1
     Then set start = i + 1.

Why greedy works:
- Every character in a partition must have all its occurrences inside it.
- The earliest valid ending point is the maximum last occurrence of
  the characters seen so far.
- Ending the partition at that point leaves the most room for later
  partitions, maximizing the number of partitions.

Example:
s = "ababcbacadefegdehijhklij"

- The first partition must include all occurrences of a, b, and c.
- Their last occurrences force the boundary to index 8.
- Close the partition, then repeat for the remaining characters.
- Result: [9, 7, 8]

Complexity:
- Time: O(n)
- Extra space: O(1), since there are only 26 lowercase letters.
*/
class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> last(26, 0);
        vector<int> result;
        for (int i = 0; i < s.size(); i++)
            last[s[i] - 'a'] = i;
        int start = 0;
        int end = 0;
        for (int i = 0; i < s.size(); i++) {
            end = max(end, last[s[i] - 'a']);
            if (i == end) {
                result.push_back(i - start + 1);
                start = i + 1;
            }
        }
        return result;
    }
};