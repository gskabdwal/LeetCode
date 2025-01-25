/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
    void rec(Node* rt,vector<int> &ans){
        if(!rt)return;

        for(auto c: rt->children)
            rec( c,ans);
        ans.push_back(rt->val);
    }
public:
    vector<int> postorder(Node* root) {   
        vector<int> ans;
        rec(root,ans);
        return ans;
    }
};