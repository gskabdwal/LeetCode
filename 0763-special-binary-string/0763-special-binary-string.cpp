class Solution {
public:
    string makeLargestSpecial(string S) {
        
        int count = 0, i = 0;
        
        vector<string> res;
        
        for (int j = 0; j < S.size(); ++j) {
            if (S[j] == '1') count++;
            else count--;
            if (count == 0) {
                res.push_back('1' + makeLargestSpecial(S.substr(i + 1, j - i - 1)) + '0');
                i = j + 1;
            }
        }

        sort(res.begin(), res.end(), greater<string>());
        
        string res2 = "";
        
        for (int j = 0; j < res.size(); ++j) res2 += res[j];
        
        return res2;
  }
};