class Solution {
public:
    int maximum69Number (int num) {
        
        string str = to_string(num);

        for(int k = 0; k<str.size(); k++){
            if(str[k]=='6'){
                str[k] = '9';    
                break;
            }
        }

        return stoi(str);
    }
};