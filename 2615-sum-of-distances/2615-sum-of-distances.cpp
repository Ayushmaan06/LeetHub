#define ll long long
class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        ll n = nums.size();
        unordered_map<ll,vector<ll>> mp, mm;
        for(ll i = 0 ; i < n ; i++)mp[nums[i]].push_back(i),mm[nums[i]].push_back(i);
        for(auto& it : mp){
            for(ll i = 1 ; i < it.second.size() ;i++)it.second[i]+=it.second[i-1];
        }
        vector<ll> arr(n);
        for(ll i = 0 ; i < n ; i++){
            if(mp[nums[i]].size()==1){arr[i]=0;continue;}
            ll j = lower_bound(mm[nums[i]].begin(), mm[nums[i]].end(),i)-mm[nums[i]].begin();
            ll ans=0;
            ll bs=mp[nums[i]][j]-i,
                as=mp[nums[i]][ mp[nums[i]].size()-1]- mp[nums[i]][j],
                bc=j*i,
                ac=(mp[nums[i]].size()-1-j)*i;
            arr[i]=(bc-bs)+(as-ac);
        }
        return arr;
    }
};