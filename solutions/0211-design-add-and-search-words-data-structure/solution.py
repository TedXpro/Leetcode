class TrieNode:
    def __init__(self):
        self._children = {}
        self._end = False

class WordDictionary:

    def __init__(self):
        self._root = TrieNode()

    def addWord(self, word: str) -> None:
        curr = self._root
        for char in word:
            if char not in curr._children:
                curr._children[char] = TrieNode()
            curr = curr._children[char]
        curr._end = True

    def search(self, word: str) -> bool:
        def dfs(node: TrieNode, idx: int):
            if idx == len(word):
                return node._end
            curr_char = word[idx]
            
            if curr_char == '.':
                for child in node._children.values():
                    if dfs(child, idx + 1):
                        return True
                return False    
                
            elif curr_char not in node._children:
                return False
            
            return dfs(node._children[curr_char], idx + 1)    
        
        return dfs(self._root, 0)


# Your WordDictionary object will be instantiated and called as such:
# obj = WordDictionary()
# obj.addWord(word)
# param_2 = obj.search(word)