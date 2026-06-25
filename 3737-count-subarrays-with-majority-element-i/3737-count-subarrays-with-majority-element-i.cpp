#define ll long long
class Solution {
public:
    int a[3]={0,1,2};
    int countMajoritySubarrays(vector<int>& nums, int x) {
        int n = nums.size();
        vector<int> pre(n+a[1],a[0]);
        for(int i = a[0] ; i <n ; i++)pre[i+a[1]]=pre[i]+(nums[i]==x ? a[1] : -a[1]);
        vector<int> al = pre;sort(al.begin(),al.end());al.erase(unique(al.begin(),al.end()),al.end());

        auto id=[&](int y){return int(lower_bound(al.begin(),al.end(),y)-al.begin())+a[1];};
        int m = al.size();
        vector<ll> b(m+a[2],a[0]);
        auto sum = [&](int i ){ll s = 0LL; for(;i>a[0];i-=(i & -i))s+=b[i];return s;};
        ll ans = 0LL;
        for(int i = a[0] ; i<=n ; i++){
            int idx = id(pre[i]);
            ans+=sum(idx -a[1]);
            for(;idx<=m; idx+=(idx & -idx))b[idx]++;
        }
        return ans;

    }
};