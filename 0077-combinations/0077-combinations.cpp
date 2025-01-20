class Solution {

    vector<vector<int>> iterativeCombine(int n, int k) {
		vector<vector<int>> result;
		int i = 0;
		vector<int> p(k, 0);
		while (i >= 0) {
			p[i]++;
			if (p[i] > n) --i;
			else if (i == k - 1) result.push_back(p);
			else {
			    ++i;
			    p[i] = p[i - 1];
			}
		}
		return result;
	}

    void combine(vector<vector<int> > &res,vector<int> &temp,int start,int num,int n ,int k){
        if(num>=k){
            res.push_back(temp);
            return;
        }
        
        for(int i = start; i<n; i++){
            temp.push_back(i+1);
            combine(res,temp,i+1,num+1,n,k);
            temp.pop_back();
        }
    }

public:

    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> >res;
        if(n<k) return res;
        vector<int> temp;
        combine(res,temp,0,0,n,k);
        return res;
    }
    
};