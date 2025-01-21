class Solution {
public:

    const vector<string> keypad = {
        "", "", "abc", "def", "ghi", "jkl",
        "mno", "pqrs", "tuv", "wxyz"
    };

    void generateCombs(string digits, int i, string comb ,vector<string>& ans){

        if(digits.empty())
            return;

        if(i==digits.size()){
            ans.push_back(comb);
            return;
        }

        int digit = digits[i]-'0';


        for(char ch: keypad[digit]){

            generateCombs(digits,i+1,comb+ch,ans);
            
        }

    }

    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        generateCombs(digits,0,"",ans);
        return ans;    
    }
};