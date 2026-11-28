class TrieNode:
    def __init__(self):
        self.children={}
        self.isEnd=False
class WordDictionary:
    def __init__(self):
        self.root=TrieNode()
    def insert(self,word:str):
        node=self.root
        for c in word:
            if c not in node.children:
                node.children[c]=TrieNode()
            node=node.children[c]
        node.isEnd=True
    def search(self,word:str):
        def dfs(i,node):
            if i==len(word):
                return node.isEnd
            char=word[i]
            if char=='.':
                return any(dfs(i+1,n) for n in node.children.values())
            elif char not in node.children:
                return False
            else:
                return dfs(i+1,node.children[char])
        return dfs(0,self.root)