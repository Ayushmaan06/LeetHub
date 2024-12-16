class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        int i=0;
        for(int num:nums){
            pq.push({num,i++});
        }
        while(k--){
            auto[p,q]=pq.top();pq.pop();
            p*=multiplier;
            pq.push({p,q});
        }
        while(!pq.empty()){
            auto[p,q]=pq.top();pq.pop();
            nums[q]=p;
        }
        return nums;
    }
};