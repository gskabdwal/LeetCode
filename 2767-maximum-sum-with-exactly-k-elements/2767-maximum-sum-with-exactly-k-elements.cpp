class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {

       int maxi = *max_element(nums.begin(),nums.end());

       return (maxi+k+maxi-1)*(k)/2; 
    }
};