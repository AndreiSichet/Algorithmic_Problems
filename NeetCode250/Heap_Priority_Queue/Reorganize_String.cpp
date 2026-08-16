/*
Reorganize String:

Goal:
    Rearrange s so that no two adjacent characters are the same.

Use:
    Max heap
    Stores {frequency, character}.

Why max heap?
    We want to use the character with the highest remaining frequency first.

Main problem:
    We cannot use the same character twice in a row.

Solution:
    Keep the previously used character outside the heap temporarily.

For each position:

    1. Take the most frequent character from heap.
    2. Add it to the result.
    3. Decrease its frequency.
    4. Put the PREVIOUS character back into heap.
    5. Store the current character as previous.

Example:

    s = "aaabbc"

    Frequencies:
        a = 3
        b = 2
        c = 1

    Heap:
        a(3), b(2), c(1)

    Take a:
        result = "a"
        a has 2 left
        keep a outside heap

    Heap:
        b(2), c(1)

    Take b:
        result = "ab"
        b has 1 left
        put previous a(2) back

    Heap:
        a(2), c(1)

    Take a:
        result = "aba"
        a has 1 left
        put b(1) back

    Continue.

If the heap is empty while a character still has
remaining frequency, then we cannot reorganize.

Time: O(n log 26) -> O(n)
Space: O(26)
*/

class Solution {
public:
    string reorganizeString(string s) {
        // Count character frequencies.
        vector<int> count(26, 0);
        for (char c : s) {
            count[c - 'a']++;
        }
        // {frequency, character}
        priority_queue<pair<int, char>> maxHeap;
        for (int i = 0; i < 26; i++) {
            if (count[i] > 0) {
                maxHeap.push({count[i],'a' + i});
            }
        }
        string result;
        // Previous character that we cannot use immediately.
        pair<int, char> previous = { 0, '#' };
        while (!maxHeap.empty()) {
            // Get the most frequent character.
            auto [frequency, character] = maxHeap.top();
            maxHeap.pop();
            // Use it.
            result += character;
            frequency--;
            // The previous character can now be used again.
            if (previous.first > 0) {
                maxHeap.push(previous);
            }
            // Current character becomes previous.
            previous = { frequency, character };
        }
        // If some character still has remaining copies,
        // it means we could not place it.
        if (previous.first > 0) {
            return "";
        }
        return result;
    }
};