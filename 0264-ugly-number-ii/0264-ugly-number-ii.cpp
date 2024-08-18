class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> uglyNumbers;
        priority_queue<long, vector<long>, greater<long>> minHeap;
        unordered_set<long> seen;
        
        minHeap.push(1);
        seen.insert(1);
        
        while (uglyNumbers.size() < n) {
            long current = minHeap.top();
            minHeap.pop();
            uglyNumbers.push_back(current);
            
            if (seen.find(current * 2) == seen.end()) {
                minHeap.push(current * 2);
                seen.insert(current * 2);
            }
            if (seen.find(current * 3) == seen.end()) {
                minHeap.push(current * 3);
                seen.insert(current * 3);
            }
            if (seen.find(current * 5) == seen.end()) {
                minHeap.push(current * 5);
                seen.insert(current * 5);
            }
        }
        
        return uglyNumbers[n - 1];
    }
};