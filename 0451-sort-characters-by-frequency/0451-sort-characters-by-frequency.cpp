class Solution {
public:
    string frequencySort(string s) {
        
        unordered_map<char,int> freq;
        vector<string> bucket(s.size()+1,"");

        for(char x: s){
            freq[x]++;
        }

        for(auto& it : freq ){
            int n = it.second;
            char c = it.first;
            bucket[n].append(n,c);

        }

        string ans;

        for(int i = s.size(); i>0; i--){

            if(bucket[i] != "")
                ans.append(bucket[i]);

        }

        return ans;
    }
};