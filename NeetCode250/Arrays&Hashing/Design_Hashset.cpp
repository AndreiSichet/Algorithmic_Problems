/*
Notes:
Implement a HashSet without using a built-in hash table.
Use a vector<bool> where the index represents the key.
hashSet[key] = true  -> key exists
hashSet[key] = false -> key does not exist

add(key):
    Set hashSet[key] to true.

remove(key):
    Set hashSet[key] to false.
    If the key does not exist, nothing happens.

contains(key):
    Return hashSet[key].

Since accessing an element by index takes O(1):

Time:
add      -> O(1)
remove   -> O(1)
contains -> O(1)
Space: O(maxKey)
This works because the key range is limited.
*/
#include<iostream>
#include<vector>
using namespace std;
class MyHashSet {
    vector<bool> myset;
public:
    MyHashSet() {
        myset.resize(1000001, false);
    }
    void add(int key) {
        myset[key] = true;
    }
    void remove(int key) {
        myset[key] = false;
    }
    bool contains(int key) {
        return myset[key];
    }
};
int main() {
    MyHashSet* obj = new MyHashSet();
    obj->add(1);
    obj->add(2);
    cout << boolalpha;
    cout << obj->contains(1) << endl; // true
    cout << obj->contains(3) << endl; // false
    obj->add(2);
    cout << obj->contains(2) << endl; // true
    obj->remove(2);
    cout << obj->contains(2) << endl; // false
    delete obj;
    return 0;
}