class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        // sort(nums.begin() , nums.end());
        // int it = lower_bound(nums.begin(),nums.end(),k)-nums.begin();
        priority_queue <long long, vector<long long>, greater<long long>> pq;
        for(int num : nums){
            pq.push(num);
        }
        int c=0;
        while(pq.top()<k){
            long long t1=pq.top();
            pq.pop();
            long long t2=pq.top();
            pq.pop();
            long long w = min(t1,t2)*2 + max(t1,t2);
            pq.push(w);
            c++;
        }
        return c;
    }
};