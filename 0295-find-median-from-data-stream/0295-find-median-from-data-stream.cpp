class MedianFinder {
public:
    priority_queue<double> max;
    priority_queue<double,vector<double>,greater<double>> min;
    MedianFinder() {
        
    }
    
    void addNum(int x) {
        if(max.size()==0 || max.top()>x){
            max.push(x);
        }else{
            min.push(x);
        }
        balanceHeap();
    }
    void balanceHeap(){
        if(max.size()>min.size()+1){
            min.push(max.top());
            max.pop();
        }
        else if(min.size()>max.size()){
            max.push(min.top());
            min.pop();
        }
    }
    double findMedian() {
    if(min.size() == max.size()) {
        return (max.top() + min.top()) / 2.0;  // Removed the extra closing parenthesis here
    } else {
        return max.top();  // Return the top of the max-heap
    }
}
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */