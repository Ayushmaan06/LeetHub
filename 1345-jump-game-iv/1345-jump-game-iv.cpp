class Solution {
public:
    bool isc(int i, int n){
        if(i>=0 && i<n)return true;
        return false;
    }
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,vector<int>> mp;
        vector<int> d (n,INT_MAX);
        d[0]=0;
        for(int i = 0 ; i < n ; i++) mp[arr[i]].push_back(i);
        queue<int> q;
        q.push(0);
        while(!q.empty()){
            int x = q.front();q.pop();
            if(x==n-1)return d[x];
            // if(arr[x]==arr[n-1])return min(d[x]+1, d[n-1]);
            int l = x-1 , r = x+1;
            if(isc(l,n) && d[l]>d[x]+1){
                d[l]=d[x]+1;
                q.push(l);
            }
            if(isc(r,n) && d[r]>d[x]+1){
                d[r]=d[x]+1;
                q.push(r);
            }
            for(int i : mp[arr[x]]){
                if(d[i]>d[x]+1){
                    d[i]=d[x]+1;
                    q.push(i);
                }
            }
            mp[arr[x]].clear();

        }
        return d[n-1];
    }
};