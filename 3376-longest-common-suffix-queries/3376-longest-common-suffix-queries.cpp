class Solution {
public:
    struct Trie {
        Trie* ch[26] = {};
        int min_sz = INT_MAX, best_i = 0;
        void insert(const string &w, int i, int j) {
            if (min_sz > w.size()) {
                best_i = i;
                min_sz = w.size();
            }
            if (j < 0)
                return;
            if (ch[w[j] - 'a'] == nullptr)
                ch[w[j] - 'a'] = new Trie();
            ch[w[j] - 'a']->insert(w, i, j - 1);
        }
        int find(const string &q, int j) {
            if (j >= 0 && ch[q[j] - 'a'] != nullptr)
                return ch[q[j] - 'a']->find(q, j - 1);
            return best_i;
        }
        ~Trie() {
            for (int i = 0; i < 26; ++i)
                delete ch[i];
        }
    };
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        Trie t;
        for (int i = 0; i < wordsContainer.size(); ++i)
            t.insert(wordsContainer[i], i, wordsContainer[i].size() - 1);
        vector<int> res;
        for (const auto &q : wordsQuery)
            res.push_back(t.find(q, q.size() - 1));
        return res;
    }
};