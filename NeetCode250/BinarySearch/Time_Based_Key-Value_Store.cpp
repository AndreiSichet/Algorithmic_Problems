/*
Time Based Key-Value Store:

Store for every key:

vector<(timestamp,value)>

Since timestamps are inserted
in increasing order, the vector
is already sorted.

set():

Append the new pair.

No sorting is needed.

get():

Binary search the vector
for the largest timestamp
that is <= the query.

Maintain:

ans = ""

If timestamp[mid] <= query:

    Save its value.

    Search right for a
    newer valid timestamp.

Otherwise:

    Search left.

Return the last valid value.

Main insight:

Each key maintains its own
sorted timeline.

Binary search finds the
latest timestamp that does
not exceed the requested one.

Important details:

- unordered_map gives O(1)
  access to each key.
- Vector stays sorted because
  timestamps are strictly increasing.
- Store the current answer
  before searching right.

Time Complexity:

set: O(1)

get: O(log m)

Space Complexity:

O(total insertions)
*/
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
class TimeMap {
    unordered_map<string, vector<pair<int, string>>> mp;
public:
    TimeMap() {}
    void set(string key, string value, int timestamp) {
        mp[key].push_back({ timestamp,value });
    }
    string get(string key, int timestamp) {
        if (mp.find(key) == mp.end())
            return "";
        vector<pair<int, string>>& values = mp[key];
        int left = 0;
        int right = values.size() - 1;
        string ans = "";
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (values[mid].first <= timestamp) {
                ans = values[mid].second;
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return ans;
    }
};
int main() {
    TimeMap timeMap;
    timeMap.set("alice", "happy", 1);
    cout << timeMap.get("alice", 1) << endl;
    cout << timeMap.get("alice", 2) << endl;
    timeMap.set("alice", "sad", 3);
    cout << timeMap.get("alice", 3) << endl;
    return 0;
}