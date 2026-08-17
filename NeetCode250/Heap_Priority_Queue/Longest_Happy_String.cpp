/*
Longest Happy String:

Goal:
    Build the longest string using at most:
        a copies of 'a'
        b copies of 'b'
        c copies of 'c'

    We cannot have:
        "aaa"
        "bbb"
        "ccc"

Use a max heap:
    {remainingCount, character}

Greedy idea:
    Always try to use the character with the highest remaining frequency.

But:
    We cannot use a character if the last two characters are already the same.

Example:

    result = "...aa"

    We cannot add another 'a'.

    Instead, take the next most frequent character.

If the most frequent character is blocked:
    Temporarily remove it from the heap.
    Use the second most frequent character.
    Put the blocked character back.

If there is no second character:
    We cannot continue.
    Return the string built so far.

Why greedy works:
    We always use the character with the largest
    remaining supply whenever it is legal.

This prevents a frequent character from being left unused at the end.

Time: O((a+b+c) log 3) -> O(n)
Space: O(3) -> O(1)
*/

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        // {remaining count, character}
        priority_queue<pair<int, char>> maxHeap;
        if (a > 0)
            maxHeap.push({ a, 'a' });
        if (b > 0)
            maxHeap.push({ b, 'b' });
        if (c > 0)
            maxHeap.push({ c, 'c' });
        string result;
        while (!maxHeap.empty()) {
            // Most frequent character.
            auto [count, ch] = maxHeap.top();
            maxHeap.pop();
            // Cannot use this character because
            // the last two characters are already ch.
            if (result.size() >= 2 && result[result.size() - 1] == ch && result[result.size() - 2] == ch) {
                // No other character available.
                if (maxHeap.empty()) {
                    break;
                }
                // Use the second most frequent character.
                auto [count2, ch2] = maxHeap.top();
                maxHeap.pop();
                result += ch2;
                count2--;
                // Put the first character back.
                maxHeap.push({ count, ch });
                // Put second character back if copies remain.
                if (count2 > 0) {
                    maxHeap.push({ count2, ch2 });
                }
            }
            else {
                // We can safely use the most frequent character.
                result += ch;
                count--;
                if (count > 0) {
                    maxHeap.push({ count, ch });
                }
            }
        }
        return result;
    }
};