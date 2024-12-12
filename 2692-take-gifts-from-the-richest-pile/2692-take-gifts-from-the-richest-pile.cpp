class Solution {
public:
    long long pickGifts(vector<int>& nums, int k) {
        priority_queue<int> pq(nums.begin(), nums.end());
        while(k--){
            int t = pq.top();
            pq.pop();
            pq.push(int(sqrt(t)));
        }
        long long ans=0;
        while(!pq.empty()){
            ans+=pq.top();
            pq.pop();
        }
        return ans;
    }
};