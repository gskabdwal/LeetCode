/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    int extractNum(string &data, int &i ){
        i++;
        int num = 0, s=1;
        if(data[i]=='-'){
            s = -1;
            i++;
        }
        while(data[i]!='*'){
            num = num *10 + data[i]-'0';
            i++;
        }
        i++;

        return s*num;
    }

    TreeNode* de(string data, int &i) {
        
        if(data[i]=='#'){
            i++;
            return NULL;
        } 

        int num = extractNum(data,i);
        auto root = new TreeNode(num);
        
        root->left = de(data, i);    
        root->right = de(data, i);    

        return root;
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        
        if(!root) return "#";

        return '*'+to_string(root->val)+'*'+serialize(root->left)+serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int i = 0;
        cout<<data;
        return de(data,i);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));