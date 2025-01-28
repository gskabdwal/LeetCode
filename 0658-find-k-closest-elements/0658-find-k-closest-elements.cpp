class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        int l = 0, r = arr.size()-k, ans = 0;
        while(l<=r){
            int m = (l+r)/2;
            if(m+k<arr.size()&&x-arr[m]>arr[m+k]-x){
                l = m+1;
            }
            else{
                ans = m;
                r = m-1;
            }
        }

        return vector<int> (arr.begin()+ans,arr.begin()+ans+k);
    }
};