class Trie {

    vector<Trie *> node; 
    bool isEnd = false;
    
public:

    Trie():node(26){
        
    }
    
    void insert(string word) {
        auto cur = this;

        for(char c: word){

            if(!cur->node[c-'a']){
                cur->node[c-'a'] = new Trie();
            }
            cur = cur->node[c-'a'];
        }
        cur->isEnd = true;
    }
    
    bool search(string word) {
        auto cur = this;

        for(char c: word){

            if(cur->node[c-'a']==NULL){
                return false;
            }
            cur = cur->node[c-'a'];
        }
        return cur->isEnd;
    }
    
    bool startsWith(string prefix) {
        auto cur = this;

        for(char c: prefix){

            if(cur->node[c-'a']==NULL){
                return false;
            }
            cur = cur->node[c-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */