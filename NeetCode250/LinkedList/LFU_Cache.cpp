/*
LFU Cache
Need to track:
1. key -> node
2. frequency -> doubly linked list
3. minFreq

Each Node stores:
key
value
freq
prev
next

Each frequency has its own LRU list.

Example:
freq 1:
A <-> B
freq 2:
C <-> D
freq 3:
E

Within each frequency:
head->next = LRU
tail->prev = MRU

GET:
If key doesn't exist:
    return -1

Otherwise:

    remove node from old
    frequency list

    increase freq

    add node to new
    frequency list as MRU


PUT existing key:

    update value
    increase frequency


PUT new key:

    if cache is full:

        go to minFreq list

        remove its LRU node

        erase it from key map

    create new node

    frequency = 1

    minFreq = 1

    add to frequency-1 list


IMPORTANT:

If the last node is removed
from minFreq:

    minFreq++

Why?

Because the previous minimum
frequency no longer exists.


LFU tie breaker:

Same frequency->LRU decides
Time:
get  = O(1) average
put  = O(1) average

Space:
O(capacity)
*/
class Node {
public:
    int key;
    int value;
    int freq;
    Node* prev;
    Node* next;
    Node(int k, int v) {
        key = k;
        value = v;
        freq = 1;
        prev = nullptr;
        next = nullptr;
    }
};
class DLL {
public:
    Node* head;
    Node* tail;
    int size;
    DLL() {
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }
    void add(Node* node) {
        Node* last = tail->prev;
        last->next = node;
        node->prev = last;
        node->next = tail;
        tail->prev = node;
        size++;
    }
    void remove(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        size--;
    }
    Node* removeLRU() {
        if (size == 0)
            return nullptr;
        Node* node = head->next;
        remove(node);
        return node;
    }
    bool empty() {
        return size == 0;
    }
};
class LFUCache {
    int capacity;
    int minFreq;
    unordered_map<int, Node*> keyToNode;
    unordered_map<int, DLL*> freqToList;
    void increaseFreq(Node* node) {
        int oldFreq = node->freq;
        // Remove from old frequency list
        freqToList[oldFreq]->remove(node);
        // If this was the last node with
        // the minimum frequency,
        // increase minFreq.
        if (oldFreq == minFreq && freqToList[oldFreq]->empty()) {
            minFreq++;
        }
        // Increase node frequency
        node->freq++;
        int newFreq = node->freq;
        // Create list if necessary
        if (!freqToList.count(newFreq)) {
            freqToList[newFreq] = new DLL();
        }
        // Add as MRU
        freqToList[newFreq]->add(node);
    }
public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        minFreq = 0;
    }
    int get(int key) {
        if (!keyToNode.count(key))
            return -1;
        Node* node = keyToNode[key];
        increaseFreq(node);
        return node->value;
    }
    void put(int key, int value) {
        if (capacity == 0)
            return;
        // Key already exists
        if (keyToNode.count(key)) {
            Node* node = keyToNode[key];
            node->value = value;
            increaseFreq(node);
            return;
        }
        // Cache is full
        if (keyToNode.size() == capacity) {
            DLL* list = freqToList[minFreq];
            Node* lru = list->removeLRU();
            keyToNode.erase(lru->key);
            delete lru;
        }
        // Create new node
        Node* node = new Node(key, value);
        keyToNode[key] = node;
        // New nodes always have frequency 1
        minFreq = 1;
        if (!freqToList.count(1)) {
            freqToList[1] = new DLL();
        }
        freqToList[1]->add(node);
    }
};