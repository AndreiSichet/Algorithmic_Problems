/*
Problem:

Transform beginWord into endWord using words from wordList.
Each transformation can change exactly one character.

Return the minimum number of words in the transformation sequence.

Key idea:

Treat every word as a node in an unweighted graph.

Two words are connected if they differ by exactly one character.

We need the shortest path from beginWord to endWord,
so we use BFS.

Visual:

hit
 |
hot
 |
dot
 |
dog
 |
cog

BFS explores the graph level by level:

Level 1: hit
Level 2: hot
Level 3: dot
Level 4: dog
Level 5: cog

Therefore the answer is 5.

How to find neighbors:

For every position in the current word, replace its character
with every lowercase letter from 'a' to 'z'.

Example:

hot

Change position 0:
aot, bot, cot, dot, ...

Change position 1:
hat, hbt, hct, ...

Change position 2:
hoa, hob, hoc, ...

If the generated word exists in the word set, it is a valid neighbor.

Visited words:

Remove a word from the unordered_set as soon as we add it to the queue.
This prevents visiting the same word multiple times.

Important:

The answer counts words, including beginWord and endWord.

If endWord is not in wordList, it is impossible to reach it.

Time:
    O(N * L * 26)
    O(N * L)

Space:
    O(N)

N = number of words
L = length of each word
*/

class Solution {
public:
    int ladderLength(string beginWord,string endWord,vector<string>& wordList) {
        unordered_set<string> words(wordList.begin(), wordList.end());
        if (!words.count(endWord)) {
            return 0;
        }
        queue<string> q;
        q.push(beginWord);
        int steps = 1;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                string word = q.front();
                q.pop();
                if (word == endWord) {
                    return steps;
                }
                for (int j = 0; j < word.size(); j++) {
                    char original = word[j];
                    for (char c = 'a'; c <= 'z'; c++) {
                        if (c == original) {
                            continue;
                        }
                        word[j] = c;
                        if (words.count(word)) {
                            q.push(word);
                            words.erase(word);
                        }
                    }
                    word[j] = original;
                }
            }
            steps++;
        }
        return 0;
    }
};