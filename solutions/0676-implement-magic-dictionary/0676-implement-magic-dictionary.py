class TrieNode:
    def __init__(self):
        self._children = {}
        self._end = False

class MagicDictionary:

    def __init__(self):
        self._root = TrieNode()

    def buildDict(self, dictionary: List[str]):
        for word in dictionary:
            curr = self._root
            for char in word:
                if char not in curr._children:
                    curr._children[char] = TrieNode()
                curr = curr._children[char]
            curr._end = True

    def search(self, searchWord: str) -> bool:
        def dfs(node: TrieNode, idx: int, modified: bool) -> bool:
            if idx == len(searchWord):
                return node._end and modified
            
            target_char = searchWord[idx]

            for char, child in node._children.items():
                if char == target_char:
                    if dfs(child, idx + 1, modified):
                        return True
                elif not modified:
                    if dfs(child, idx + 1, True):
                        return True
            
            return False
        return dfs(self._root, 0, False)


# Your MagicDictionary object will be instantiated and called as such:
# obj = MagicDictionary()
# obj.buildDict(dictionary)
# param_2 = obj.search(searchWord)