class Node:
    def __init__(self):
        self.link = [None]*26
        self.flag =False

class Trie:

    def __init__(self):
        self.root = Node()
    
    def insert(self, word: str) -> None:
        curr = self.root
        for w in word:
            ind = ord(w)- ord('a')
            if curr.link[ind] is None:
                newNode = Node()
                curr.link[ind] = newNode
            curr = curr.link[ind]
        curr.flag = True

    
    def search(self, word: str) -> bool:
        curr = self.root
        for w in word:
            ind = ord(w)- ord('a')
            if curr.link[ind] is None:
                return False
            curr = curr.link[ind]
        return curr.flag
        

    def startsWith(self, prefix: str) -> bool:
        curr = self.root
        for w in prefix:
            ind = ord(w)- ord('a')
            if curr.link[ind] is None:
                return False
            curr = curr.link[ind]
        return True
        

# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)