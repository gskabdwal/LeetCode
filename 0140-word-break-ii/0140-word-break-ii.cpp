class TrieNode {
public:
    TrieNode* children[26];
    bool isWord;

    TrieNode() {
        isWord = false;
        for (int i = 0; i < 26; i++) children[i] = nullptr;
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() { root = new TrieNode(); }

    void insert(string word) {
        TrieNode* node = root;
        for (char c : word) {
            if (!node->children[c - 'a']) node->children[c - 'a'] = new TrieNode();
            node = node->children[c - 'a'];
        }
        node->isWord = true;
    }

    bool search(string word) {
        TrieNode* node = root;
        for (char c : word) {
            if (!node->children[c - 'a']) return false;
            node = node->children[c - 'a'];
        }
        return node->isWord;
    }
};

class Solution {
public:
    Trie trie;
    unordered_map<int, vector<string>> memo;

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for (string word : wordDict) trie.insert(word);
        return dfs(s, 0);
    }

    vector<string> dfs(string& s, int index) {
        if (index == s.size()) return {""};  // Base case: empty string
        if (memo.count(index)) return memo[index];

        vector<string> result;
        TrieNode* node = trie.root;

        for (int i = index; i < s.size(); i++) {
            char c = s[i] - 'a';
            if (!node->children[c]) break;  // Stop early if prefix doesn't exist
            node = node->children[c];

            if (node->isWord) {
                string word = s.substr(index, i - index + 1);
                vector<string> subList = dfs(s, i + 1);
                for (string sub : subList) {
                    result.push_back(word + (sub.empty() ? "" : " ") + sub);
                }
            }
        }
        return memo[index] = result;
    }
};
