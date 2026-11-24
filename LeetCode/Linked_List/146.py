class Node:
    def __init__(self,key:int,value:int):
        self.key=key
        self.value=value
        self.prev=None
        self.next=None
class LRUCache:

    def __init__(self, capacity: int):
        self.capacity=capacity
        self.cache={}
        self.left=Node(0,0)
        self.right=Node(0,0)
        self.left.next=self.right
        self.right.prev=self.left
    
    def remove(self,node:Node)->None:
        node.prev.next=node.next
        node.next.prev=node.prev

    def add(self,node:Node)->None:
        node.next=self.left.next
        self.left.next.prev=node
        node.prev=self.left
        self.left.next=node

    def get(self, key: int) -> int:
        node=self.cache.get(key)
        if not node:
            return -1
        self.remove(node)
        self.add(node)
        return node.value

    def put(self, key: int, value: int) -> None:
        if key in self.cache:
            node = self.cache[key]
            self.remove(node)
            node.value = value
            self.add(node)
        else:
            node = Node(key, value)
            self.cache[key] = node
            self.add(node)

        if len(self.cache) > self.capacity:
            lru = self.right.prev
            self.remove(lru)
            del self.cache[lru.key]

        
        


# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)