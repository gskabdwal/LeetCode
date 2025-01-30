
class TrieNode:
    def __init__(self):
        self.children = {}
        self.is_word = False

def buildTrie(dictionary):
    root = TrieNode()
    for word in dictionary:
        node = root
        for ch in word:
            if ch not in node.children:
                node.children[ch] = TrieNode()
            node = node.children[ch]
        node.is_word = True
    return root

class Solution:
    def minExtraChar(self, s, dictionary):
        root = buildTrie(dictionary)
        n = len(s)
        dp = [float('inf')] * (n + 1)
        dp[-1] = 0  # No extra character for an empty string

        for start in reversed(range(n)):
            dp[start] = dp[start + 1] + 1  # Initialize with worst-case scenario
            node = root
            for end in range(start, n):
                if s[end] not in node.children:
                    break
                node = node.children[s[end]]
                if node.is_word:
                    dp[start] = min(dp[start], dp[end + 1])
        
        return dp[0]   