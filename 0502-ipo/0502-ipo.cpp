class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue<int> pq; 
        vector<pair<int,int>> v;
        int n = profits.size();
        for(int i = 0 ; i < n ; i++) v.push_back({capital[i], profits[i]});
        sort(v.begin(), v.end());
        int lc = 0;
        while(k--) {
            while(lc < n && v[lc].first <= w) {
                pq.push(v[lc].second);
                lc++;
            }
            if(pq.empty()) break;
            w += pq.top();
            pq.pop();
        }
        return w;
    }
};