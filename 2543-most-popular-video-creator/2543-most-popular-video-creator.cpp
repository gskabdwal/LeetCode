class Solution {
public:
    vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
        
        vector<vector<string>> ans;
        map<string, long long> mpp;
        map<string, set<pair<int,string>>> npp;
        long long maxi = 0;

        for(int i=0; i<creators.size(); i++){

            mpp[creators[i]] += views[i];
            maxi = max(maxi,mpp[creators[i]]);
            //cout<<maxi<<" ";
            npp[creators[i]].insert({-views[i],ids[i]});
            if(npp[creators[i]].size()>1){
                npp[creators[i]].erase(prev(npp[creators[i]].end()));
            }
        }


        for(auto it = mpp.rbegin(); it!=mpp.rend(); it++){
            if(it->second==maxi){
                vector<string> t = {it->first,string((npp[it->first].begin())->second)};
                ans.push_back(t);
            }
        }

        return ans;
    }
};