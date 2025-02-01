class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& arr) {
        
        int n = arr.size(), ind = -1;

        for(int i = n-2; i>=0; i--){
            if(arr[i]>arr[i+1]){
                ind = i;
                break;
            } 
        }

        if(ind ==-1) return arr;
        int sm = arr[ind],  k = -1;
        for(int i=n-1; i>ind; i--){
            if(arr[i]<arr[ind]&& arr[i] != arr[i-1]){
                swap(arr[ind],arr[i]);
                break;
            }
        }

        
        return arr;
    }
};