class Solution {
public:

    const vector<string> keypad = {
        "", "", "abc", "def", "ghi", "jkl",
        "mno", "pqrs", "tuv", "wxyz"
    };

    void generateCombs(string digits, int i, string &comb ,vector<string>& ans){

        if(digits.empty())
            return;

        if(i==digits.size()){
            ans.push_back(comb);
            return;
        }

        int digit = digits[i]-'0';


        for(char ch: keypad[digit]){
            comb += ch;
            generateCombs(digits,i+1,comb,ans);
            comb.pop_back();
        }

    }

    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        string comb;
        generateCombs(digits,0,comb,ans);
        return ans;    
    }
};