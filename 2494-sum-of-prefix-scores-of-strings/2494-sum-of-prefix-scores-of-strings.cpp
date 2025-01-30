class Solution {
    class Node{
        public:
            Node* child[26]; 
            int prefix;

        Node(){
            for(int i=0; i<26; i++){
                child[i] = NULL;
                prefix = 0;
            }
        }               
    };

    class Trie{
        Node* root = new Node();
        public:

            void insert(string &word){

                auto node = root;

                for(char ch: word){

                    if(node->child[ch-'a']==NULL){
                        node->child[ch-'a'] = new Node();
                    }
                    node = node->child[ch-'a'];
                    node->prefix++;
                }
                
            }

            int getPrefix(string &word){
                auto node = root;
                int cnt = 0;

                for(char ch: word){

                    if(node->child[ch-'a']==NULL){
                        return cnt;
                    }
                    node = node->child[ch-'a'];
                    cnt += node->prefix;
                }
                return cnt;
            }

    };

public:
    vector<int> sumPrefixScores(vector<string>& words) {
        
        Trie t;
        vector<int> ans;

        for(string word : words){
            t.insert(word);
        }

        for(string word : words){
            ans.push_back(t.getPrefix(word));
        }

        return ans;
    }
};