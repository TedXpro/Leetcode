class DLL:

    def __init__(self, key, value, next = None, prev = None):
        self.key = key
        self.value = value 
        self.next = next
        self.prev = prev

class LRUCache:

    def __init__(self, capacity: int):
        self.capacity = capacity
        self.cache: dict[int, DLL] = {}
        self.head = DLL(-1, -1)
        self.tail = DLL(-1, -1)
        self.head.next = self.tail
        self.tail.prev = self.head

    def moveToHead(self, node: DLL, justInsert = False) -> None:
        if justInsert is False:
            node.prev.next = node.next
            node.next.prev = node.prev

        node.next = self.head.next
        self.head.next.prev = node
        node.prev = self.head
        self.head.next = node
    
    def remove(self, node: DLL) -> None:
        node.prev.next = node.next
        node.next.prev = node.prev
    
    def add_first(self, node: DLL) -> None:
        node.next = self.head.next
        self.head.next.prev = node
        node.prev = self.head
        self.head.next = node

    def get(self, key: int) -> int:
        if key not in self.cache:
            return -1
        
        self.remove(self.cache[key])
        self.add_first(self.cache[key])
        
        return self.cache[key].value

    def put(self, key: int, value: int) -> None:
        if key in self.cache:
            self.cache[key].value = value # update the value

            self.remove(self.cache[key])
            self.add_first(self.cache[key])
        else:
            node = DLL(key, value)
            self.cache[key] = node

            self.add_first(node)

        if len(self.cache) > self.capacity and self.tail.prev is not self.head:
            toDel = self.tail.prev
            self.remove(toDel)
            del self.cache[toDel.key]

            

# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)    