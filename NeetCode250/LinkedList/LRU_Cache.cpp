/*
LRU Cache:
Need two data structures.
Hash Map: key->node for O(1) lookup.
Doubly Linked List for O(1) insertion and deletion.
Store in each node:
key
value
prev
next
Use dummy head and tail.
Least Recently Used
head->next
Most Recently Used
tail->prev

get(key):
If missing:
return -1
Otherwise:
Remove node.
Insert at end.
Return value.

put(key,value):
If key exists:
Update value.
Move node to end.
Otherwise:
Create node.
Insert at end.
If capacity exceeded:
Remove head->next
Erase key from map.

Main insight:
Hash map finds nodes.
Linked list maintains usage order.
Together they provide O(1) get and put.
Time Complexity: O(1)
Space Complexity: O(capacity)
*/
class Node {
public:
    int key;
    int value;
    Node* prev;
    Node* next;

    Node(int k, int v) {
        key = k;
        value = v;
        prev = nullptr;
        next = nullptr;
    }
};
class LRUCache {
    unordered_map<int, Node*> mp;
    Node* head;
    Node* tail;
    int cap;
    void remove(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    void insert(Node* node) {
        Node* prev = tail->prev;
        prev->next = node;
        node->prev = prev;
        node->next = tail;
        tail->prev = node;
    }
public:
    LRUCache(int capacity) {
        cap = capacity;
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
    }
    int get(int key) {
        if (mp.find(key) == mp.end())
            return -1;
        Node* node = mp[key];
        remove(node);
        insert(node);
        return node->value;
    }
    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            Node* node = mp[key];
            node->value = value;
            remove(node);
            insert(node);
            return;
        }
        Node* node = new Node(key, value);
        mp[key] = node;
        insert(node);
        if (mp.size() > cap) {
            Node* lru = head->next;
            remove(lru);
            mp.erase(lru->key);
            delete lru;
        }
    }
};