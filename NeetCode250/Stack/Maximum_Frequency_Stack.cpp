/*
Maximum Frequency Stack:

Maintain two hash maps.

freq[value]
    -> current frequency
       of each value.

group[f]
    -> stack containing all
       values whose frequency
       became f.

Also maintain:

maxFreq
    -> highest frequency
       currently present.

Push:

1. Increase frequency.
2. Push value into
   group[frequency].
3. Update maxFreq.

Pop:

1. Pop from group[maxFreq].
2. Decrease its frequency.
3. If group[maxFreq] becomes
   empty, decrement maxFreq.

Main insight:

Instead of searching for the
most frequent element every
time, group elements by
frequency.

Each frequency has its own
stack, so ties are broken
automatically by recency
(last pushed).

Time Complexity:

push -> O(1)

pop -> O(1)

Space Complexity:

O(n)
*/
#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;
class FreqStack {
    unordered_map<int, int> freq;
    unordered_map<int, stack<int>> group;
    int maxFreq;
public:
    FreqStack() {
        maxFreq = 0;
    }
    void push(int val) {
        freq[val]++;
        int f = freq[val];
        group[f].push(val);
        maxFreq = max(maxFreq, f);
    }
    int pop() {
        int val = group[maxFreq].top();
        group[maxFreq].pop();
        freq[val]--;
        if (group[maxFreq].empty())
            maxFreq--;
        return val;
    }
};
int main() {
    FreqStack fs;
    fs.push(5);
    fs.push(7);
    fs.push(5);
    fs.push(7);
    fs.push(4);
    fs.push(5);
    cout << fs.pop() << endl;
    cout << fs.pop() << endl;
    cout << fs.pop() << endl;
    cout << fs.pop() << endl;
    return 0;
}