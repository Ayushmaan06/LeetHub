class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& me) {
        priority_queue<long long, vector<long long>, greater<long long>> free;
        priority_queue<pair<long long,long long>, vector<pair<long long,long long>>, greater<pair<long long,long long>>> end;
        long long t = 0LL;
        vector<long long> ans(n,0LL);
        for(long long i = 0 ; i < n ; i++)free.push(i);
        sort(me.begin(),me.end());
        for(vector<int> v : me){
            long long s = v[0],e=v[1],d=v[1]-v[0];
            while(!end.empty() && end.top().first <= s) {
                free.push(end.top().second);
                end.pop();
            }
            if(!free.empty()){
                long long f=free.top();free.pop();
                ans[f]++;
                end.push({e,f});
            }
            else{
                long long ss = end.top().first,r=end.top().second;end.pop();
                ans[r]++;
                end.push({ss+d,r});
            }
        }
        return max_element(ans.begin(),ans.end())-ans.begin();
    }
};