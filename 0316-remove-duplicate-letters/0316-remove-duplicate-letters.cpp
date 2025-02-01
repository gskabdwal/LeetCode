class Solution {
public:
    string removeDuplicateLetters(string s) {
        
        string ans;
        vector<int> last(26), seen(26);
        stack<char> st;

        for(int i=0; i<s.size(); i++){

            last[s[i]-'a'] = i;
        }


        for(int i=0; i<s.size(); i++){
            
            if(seen[s[i]-'a']) continue;

            while(st.size()&&st.top()>s[i]&&i<last[st.top()-'a']){
                seen[st.top()-'a'] = false;
                st.pop();
            }
            
            st.push(s[i]);
            seen[s[i]-'a'] = true;
        }
      
        while(st.size()){ 
            ans = st.top()+ans;
            st.pop();
        }

        return ans;
    }
};