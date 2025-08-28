class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(int s : stones)pq.push(s);
        while(pq.size()>1){
            int x=pq.top();pq.pop();int y = pq.top(); pq.pop();
            pq.push(abs(x-y));
        }
        return pq.top();
    }
};