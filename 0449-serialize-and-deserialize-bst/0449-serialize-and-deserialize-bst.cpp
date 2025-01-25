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
    string res = "";
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        
        if(!root){
            res+="$";
            return "$";
        }


        res += to_string(root->val);
        res += ",";
        serialize(root->left);
        serialize(root->right);
        
        return res;
    }

    int i = 0;
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        
        
        if(i>=data.size() || data[i]=='$'){ 
            i++;
            return NULL;    
        }
        string num = "";

        while(i<data.size()&&data[i]!=',') num += data[i++];
        i++;
        TreeNode* root = new TreeNode(stoi(num));

        root->left = deserialize(data);
        root->right = deserialize(data);

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;