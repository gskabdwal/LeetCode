class SGTree{
public:
    vector<int> seg;
    SGTree(int n){
        seg.resize(4*n+1);
    }
    void build(int ind, int low, int high){
        if(low==high){
            seg[ind] = 1;
            return;
        }
        int mid = (low+high)/2;
        build(2*ind+1,low,mid);
        build(2*ind+2,mid+1,high);

        seg[ind] = seg[2*ind+1]+seg[2*ind+2];
    }
    int query(int ind, int low, int high, int i){
        if(low==high){
            return low; // returning position, to place current person
        }
        int mid = (low+high)/2;
        int left = seg[2*ind+1];
        int right = seg[2*ind+2];
        if(i<=left){
            return query(2*ind+1,low,mid,i);
        }
        else{
            return query(2*ind+2,mid+1,high,i-left); //if moving to right, subtract available positions of left tree
        }
    }
    void update(int ind, int low, int high, int i){
        if(low==high){
            seg[ind] = 0;
            return;
        }
        int mid = (low+high)/2;
        if(i<=mid){
            update(2*ind+1,low,mid,i);
        }
        else{
            update(2*ind+2,mid+1,high,i);
        }
        seg[ind] = seg[2*ind+1]+seg[2*ind+2];
    }
};
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int n = people.size();
        sort(people.begin(), people.end(), [&](vector<int>a, vector<int>b){
            return a[0]<b[0] || (a[0]==b[0] && a[1]>b[1]);
        });
        
        SGTree sg(n);
        sg.build(0,0,n-1);

        vector<vector<int>> res(n);

        for(int i=0; i<n; i++){
            int pos = sg.query(0,0,n-1,people[i][1]+1);
            res[pos] = people[i];
            sg.update(0,0,n-1,pos);
        }
        return res;
    }
};