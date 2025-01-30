class Solution {
public:
    // jo number hoga uske length return karne ke liye
    // dekho pehle niche wala pado...bichch ke chakkar me uper
    // se chla jaeyga...samjhe....
    int length(int n){
        string ans=to_string(n); 
        
        return ans.size();
    }
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> unst;
        //  dekho agr mujhe common prefix pta hia lo longest ho
        // simple n
        // to kyu n mai pehle array ka sab 
        // prefix daal du
        // aur second ka nikalte time check kr lu..
        // kya bolte ho...samjha me aaya kya \U0001fae0\U0001fae0
        for(auto it:arr1){
            while(it>0){
                // dekho agr num 123 hai to prefix kya hoga
                // 1 12 123 
                // bas ye loop vhi kaam kr rha hai...\U0001f44d\U0001f44d\U0001f44d
                unst.insert(it);
                it/=10;
            }
        }
        int maxi=0;
        for(auto it:arr2){
            while(it>0){
                // bas same kaam dusre array ke liye lekin
                // check krenge kya vo kisi array 1 ke 
                // prefix se match kar rha...
                if(unst.find(it)!=unst.end()){

                    // ye kya abhi bhai, abhi to tumne bola tha
                    // common pta kro aur ye kya
                    // arey bhai hame number ka 
                    // lemgth chaiye n
                    // esiloiye ek function bnaya hai
                    // uske liye...smjhe
                    maxi=max(maxi,length(it));

                    // break kyu kiya????
                    // dekho...bhai agr 
                    // 1234 match kr gya...aur hme 
                    // length maximum chaiye....to kya ham use chhote
                    // portion ko check krenge nhi n..
                    // bas esiliye break kiya hai...
                    break;
                }
                it/=10;
            }
        }
        // length jo maximum prefix match huaa...
        // machate rho....❤️\U0001f60a✅
        return maxi;
    }
};