class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        
        sort(people.begin(),people.end());

        int cnt = 0, l = 0, r = people.size()-1;

        while(l<=r){

            if(people[l]+people[r]>limit){
                r--;
            }
            else{
                l++,r--;
            }
            cnt++;
        }

        return cnt;
    }
};