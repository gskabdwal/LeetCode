class MedianFinder {
    priority_queue<int> min;
    priority_queue<int,vector<int>, greater<int>> max; 
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(!min.size()||min.top()>num){
            min.push(num);
        }
        else{ max.push(num);}

        if(max.size()<min.size()-1){
            max.push(min.top());
            min.pop();
        }
        else if(max.size()>min.size()){
            min.push(max.top());
            max.pop();
        }
    }
    
    double findMedian() {
        if(min.size()==max.size()){
            return (1.0*min.top()+max.top())/2;
        }
        return min.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */