#define ll long long

ll cal(vector<int> &fr) // function for calculating the value of the window
{
    ll ans = 0;
 
    for(int i=0; i<32; ++i)
    {
        if(fr[i])          
            ans |= 1<<i;
    }
    
    return ans;
}

void add(vector<int> &fr, int val) // function for removing from window
{
    for(int i=0; i<32; ++i)
    {
        if( val&(1<<i) ) 
            fr[i]++;
    }   
}

void sub(vector<int> &fr, int val) // function for removing from window
{
    for(int i=0; i<32; ++i)
    {
        if( val&(1<<i) ) 
            fr[i]--;
    }   
}

class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
            
        int n = nums.size();
        
        vector<int> fr(32, 0);
        
        int l = 0;
        
        ll ans = 1e9+1, curr = 0;
        
        for(int r =0; r<n; r++){
            
            curr |= nums[r]; 
            add(fr,nums[r]); 

            while(curr > k && l < r)
            {
                ans = min(ans, abs(curr-k));
                sub(fr, nums[l]);
                curr = cal(fr);
                l++;
            }

            ans = min(ans, abs(curr-k));
            if(ans == 0) return 0;    
        }

        return ans;   
    }
};