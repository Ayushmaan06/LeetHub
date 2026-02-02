#define ll long long
class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        ll ans = LLONG_MAX, sum = 0, n = nums.size();
        multiset<int> L, R;
        int req = k - 1; 
        int i = 1, j = 1;
        while(j < n) {
            int val = nums[j];
            L.insert(val); sum += val;
            if (L.size() > req) { 
                int maxL = *L.rbegin();
                L.erase(prev(L.end()));
                sum -= maxL;
                R.insert(maxL);
            }
            if (j - i > dist) { 
                val=nums[i];
                auto it = L.find(val);
                if (it != L.end()) { 
                    L.erase(it);
                    sum -= val;
                    if (!R.empty()) {
                        int minR = *R.begin();
                        R.erase(R.begin());
                        L.insert(minR);
                        sum += minR;
                    }
                } 
                else R.erase(R.find(val));
                i++;
            }
            if (j - i + 1 >= req)  ans = min(ans, sum);
            j++;
        }
        return ans + nums[0];
    }
};