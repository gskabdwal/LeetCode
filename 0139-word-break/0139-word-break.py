class TrieNode:
    def __init__(self):
        self.isWord = False
        self.child = defaultdict(TrieNode)
    
    def addWord(self, word):
        cur = self
        for c in word:
            cur = cur.child[c]
        cur.isWord = True

class Solution:
    def wordBreak(self, s, wordDict):
        root = TrieNode()
        for word in wordDict:
            root.addWord(word)
            
        n = len(s)
        dp = [False] * (n+1)
        dp[n] = True
        
        for i in range(n-1, -1, -1):
            cur = root
            for j in range(i+1, n+1):
                c = s[j-1]
                if c not in cur.child: break  # s[i:j] not exist in our trie
                cur = cur.child[c]
                if cur.isWord and dp[j]:
                    dp[i] = True
                    break
        
        return dp[0]