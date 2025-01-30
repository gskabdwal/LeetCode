class Solution {
public:
    class Node {
        public:
            Node* child[26];
            int count = 0;
        
    };
    
    void add(Node* head, string s, int ind){
        Node* ptr = head;
        for(int i = ind; i < s.size(); ++i){
            int c = s[i] - 'a';
            if(ptr->child[c] == NULL) ptr->child[c] = new Node();
            ptr = ptr->child[c];
            ptr->count++;
        }
    }
    
    void remove(Node* head, string s, int ind){
        Node* ptr = head;
        for(int i = ind; i < s.size(); ++i){
            ptr = ptr->child[s[i] - 'a'];
            ptr->count--;
        }
    }
    
    string check(Node* head, string s, int ind){
        Node* ptr = head;
        string ans = "";
        for(int i = ind; i < s.size(); ++i){
            int c = s[i] - 'a';
            if(ptr->child[c] == NULL) return ans;
            ans += s[i];
            ptr = ptr->child[c];
            if(ptr->count < 1) return ans;
        }
        return s + s;
    }
    
    vector<string> shortestSubstrings(vector<string>& arr) {
        vector<string> ans;
        Node* head = new Node();
        for(auto s: arr){             // Add all the strings to the trie
            for(int i = 0; i < s.size(); ++i) add(head, s, i);   
        }
        for(auto s: arr){
            string res = s + s;
            for(int i = 0; i < s.size(); ++i) remove(head, s, i);  // remove the current string from trie
            for(int i = 0; i < s.size(); ++i){                     // iterate over each substring starting at i th and check for the uncommon string length
                string t = check(head, s, i);              
                if(t.size() < res.size() || (t.size() == res.size() && t < res) ) res = t;  // store it in result if length is less or lexicographically smaller if equal 
            }
            ans.push_back((res.size() <= s.size())?res: "");        // add res to final answer
            for(int i = 0; i < s.size(); ++i) add(head, s, i);      // add back the current string to the trie
        }
        return ans;
    }
};