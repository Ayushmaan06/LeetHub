class FreqStack {
public:
    priority_queue<vector<int>> pq;
    unordered_map<int, int> mp; 
    int t = 0; 

    FreqStack() {
    }
    
    void push(int val) {
        mp[val]++; 
        pq.push({mp[val], t++, val});
    }
    
    int pop() {
        vector<int> top = pq.top();
        pq.pop();
        int val = top[2];
        mp[val]--; 
        return val;
    }
};