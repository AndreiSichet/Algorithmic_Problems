/*
Notes:
Because the key range is limited:
    0 <= key <= 1,000,000
Use a vector as a direct-address table.
The key itself is used as the index:
    map[key] = value;
Use -1 to represent that a key does not exist.
put(key, value):
    map[key] = value;
    If the key already exists, this automatically updates its value.

get(key):
    return map[key];
    If the key does not exist, it returns -1.

remove(key):
    map[key] = -1;

Example:
put(2, 10)  -> map[2] = 10
put(2, 20)  -> map[2] = 20 (update)
get(2)       -> 20
remove(2)    -> map[2] = -1
get(2)       -> -1

Time:
put      -> O(1)
get      -> O(1)
remove   -> O(1)

Space: O(maxKey)
This works because the key range is limited.
*/
class MyHashMap {
    vector<int> mymap;
public:
    MyHashMap() {
        mymap.resize(1000001, -1);
    }

    void put(int key, int value) {
        mymap[key] = value;
    }

    int get(int key) {
        return mymap[key];
    }

    void remove(int key) {
        mymap[key] = -1;
    }
};
int main() {
    MyHashMap myHashMap;
    myHashMap.put(1, 1);
    myHashMap.put(2, 2);
    cout << myHashMap.get(1) << endl; // 1
    cout << myHashMap.get(3) << endl; // -1
    myHashMap.put(2, 1);
    cout << myHashMap.get(2) << endl; // 1
    myHashMap.remove(2);
    cout << myHashMap.get(2) << endl; // -1
    return 0;
}