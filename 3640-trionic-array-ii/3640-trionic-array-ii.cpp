#define ll long long
class Solution {
public:
    long long maxSumTrionic(vector<int>& nums) {
        ll n = nums.size();
        ll INF = 1e16;
        ll s1 = -INF; 
        ll s2 = -INF; 
        ll s3 = -INF; 
        ll ans = -INF;
        for(int i = 1; i < n; i++) {
            ll cur = nums[i];
            ll prev = nums[i-1];
            ll ns1 = -INF, ns2 = -INF, ns3 = -INF;

            if (cur > prev) {
                ns1 = cur + max(prev, s1);
                if (s2 != -INF) ns3 = max(ns3, s2 + cur);
                if (s3 != -INF) ns3 = max(ns3, s3 + cur);
                
            } else if (cur < prev) {
                if (s1 != -INF) ns2 = max(ns2, s1 + cur);
                if (s2 != -INF) ns2 = max(ns2, s2 + cur);
            }
            s1 = ns1; 
            s2 = ns2; 
            s3 = ns3;
            ans = max(ans, s3);
        }
        
        return ans;
    }
};