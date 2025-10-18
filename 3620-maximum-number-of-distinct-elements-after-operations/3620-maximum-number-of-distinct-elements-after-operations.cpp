class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        unordered_set<int> s;
        int ans=0;
        int n = nums.size();
        for (int i = 0; i < n;) {
            int l = nums[i] - k, h = nums[i] + k, x = nums[i];
            int d = l;
            int cnt = 0;
            while (i + cnt < n && nums[i + cnt] == x) cnt++;
            while(s.count(d))d++;
            int y=min(cnt,h-d+1);
            for(int i = 0 ; i < y ; i++)s.insert(d+i);
            ans+=min(cnt,h-d+1);
            i += cnt;  
        }
        return ans;
    }
};
