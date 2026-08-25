/*
Verifying An Alien Dictionary:

Compare every pair of adjacent words.

We only need to check:

    words[i] <= words[i + 1]

If every adjacent pair is correctly ordered,
the entire list is sorted.

First build a rank for every character.

Example:

    order = "hlabcdefg..."

Then:

    h -> 0
    l -> 1
    a -> 2
    b -> 3
    ...

Now compare two words character by character.

For each position:

    If the characters are equal:
        continue.

    If rank of first character is greater:
        the words are in the wrong order.

    If rank of first character is smaller:
        this pair is correctly ordered.

        We can stop comparing this pair.

Important edge case:

    ["apple", "app"]

The characters:

    a == a
    p == p
    p == p

match completely.

But "apple" is longer.

If one word is a prefix of the other,
the shorter word must come first.

Therefore:

    "app" before "apple" -> valid

    "apple" before "app" -> invalid

Time:
    O(n * L)

where n is the number of words and L is the
average word length.

Space:
    O(1)

The rank array always contains 26 characters.
*/

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int> rank(26);
        for (int i = 0; i < 26; i++) {
            rank[order[i] - 'a'] = i;
        }
        for (int i = 0; i + 1 < words.size(); i++) {
            string& word1 = words[i];
            string& word2 = words[i + 1];
            int len = min(word1.size(), word2.size());
            for (int j = 0; j < len; j++) {
                if (word1[j] == word2[j]) {
                    continue;
                }
                if (rank[word1[j] - 'a'] > rank[word2[j] - 'a']) {
                    return false;
                }
                break;
            }
            // word2 cannot be a prefix of word1.
            if (word1.size() > word2.size() && word1.substr(0, len) == word2) {
                return false;
            }
        }
        return true;
    }
};