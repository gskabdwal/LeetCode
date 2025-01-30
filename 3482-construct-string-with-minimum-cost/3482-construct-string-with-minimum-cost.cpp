constexpr int INF = 2e9;
struct TrieNode {
    int len = 0, sfx = 0, dict = 0, cost = INF;
    std::array<int, 26> next;
};

struct Trie {
    static constexpr int unassigned = 0, root = 1;
    std::vector<TrieNode> tree;

    int newNode(TrieNode node) {
        tree.push_back(node);
        return tree.size() - 1;
    }

    Trie() {
        tree.assign(2, {});
        tree[unassigned].len = -1;
        tree[unassigned].next.fill(root);
    }

    void addWord(std::string_view s, int cost) {
        int u_id = root;
        for (char c : s) {
            int x = c - 'a';
            if (tree[u_id].next[x] == unassigned) {
                tree[u_id].next[x] = newNode({.len = tree[u_id].len + 1});
            }
            u_id = tree[u_id].next[x];
        }
        tree[u_id].cost = std::min(tree[u_id].cost, cost);
    }

    void ahoCorasick() {
        std::deque<int> q{root};
        while (!q.empty()) {
            auto [u, u_id] = ref(q.front());
            q.pop_front();
            for (int x = 0; x < 26; ++x) {
                auto [v, v_id] = ref(u->next[x]);
                auto [s, s_id] = ref(tree[u->sfx].next[x]);
                if (v_id == unassigned) {
                    u->next[x] = s_id;
                } else {
                    v->sfx = s_id;
                    v->dict = s->cost != INF ? s_id : s->dict;
                    q.push_back(v_id);
                }
            }
        }
    }

    std::tuple<TrieNode*, int> ref(int id) {
        return {&tree[id], id};
    }

    TrieNode* operator[](int id) {
        return &tree[id];
    }
};

class Solution {
public:
    int minimumCost(string target, vector<string>& words, vector<int>& costs) {
        int n = target.size(), m = words.size();
        Trie trie;
        for (int i = 0; i < m; ++i) {
            trie.addWord(words[i], costs[i]);
        }
        trie.ahoCorasick();
        std::vector<int> dp(n + 1, INF);
        dp[0] = 0;
        auto u = trie[Trie::root];
        for (int i = 1; i <= n; ++i) {
            int x = target[i - 1] - 'a';
            u = trie[u->next[x]];
            auto v = u->cost != INF ? u : trie[u->dict];
            while (v->cost != INF) {
                dp[i] = std::min(dp[i], dp[i - v->len] + v->cost);
                v = trie[v->dict];
            }
        }
        return dp[n] == INF ? -1 : dp[n];
    }
};