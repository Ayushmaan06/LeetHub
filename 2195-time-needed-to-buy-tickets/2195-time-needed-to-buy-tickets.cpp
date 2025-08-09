class Solution {
public:
    int timeRequiredToBuy(vector<int>& t, int k) {
        deque<int> dq;
        int n = t.size();
        for(int i = 0 ; i < n ; i++)dq.push_back(i);
        int ans=0;
        while(t[k]){
            int p = dq.front();
            t[p]--;
            if(t[p]==0)dq.pop_front();
            else{
                dq.pop_front();
                dq.push_back(p);
            }
            ans++;
        }
        return ans;
    }
};