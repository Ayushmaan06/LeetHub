#define ll long long
class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        priority_queue<vector<ll>, vector<vector<ll>>, greater<vector<ll>>> pq;
        int n = workerTimes.size();
        for(int i =0; i < n ; i++){
            pq.push({workerTimes[i],i,1});
        }
        vector<int> t(n,0);
        while(mountainHeight--){
            ll j = pq.top()[1],x=pq.top()[2],w=pq.top()[0];
            t[j]=x;
            pq.pop();
            pq.push({w+workerTimes[j]*(x+1),j,x+1});
        }
        ll ans=-1,k=0;
        for(ll i : t){
           ll y = ((i*(i+1))/2)*((ll)workerTimes[k++]);
            ans=max(ans,y);
        }
        return ans;
    }
};