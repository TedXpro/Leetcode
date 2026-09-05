class TrieNode:

    def __init__(self):
        self._children = {}
        self._end = False


class Trie:

    def __init__(self):
        self._root = TrieNode()

    def insert(self, word: str):
        curr = self._root
        for char in word:
            if char not in curr._children:
                curr._children[char] = TrieNode()
            curr = curr._children[char]

        curr._end = True

    def search(self, word: str):
        curr = self._root
        for char in word:
            if char not in curr._children:
                return False
            curr = curr._children[char]

        return curr._end

    def startsWith(self, prefix: str):
        curr = self._root
        for char in prefix:
            if char not in curr._children:
                return False
            curr = curr._children[char]
        return True


# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)
