class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> v(3);
        for(int n : nums) v[n%3].push_back(n);
        int s = accumulate(nums.begin(),nums.end(),0);
        if(s%3 == 0)return s;
        if(s%3 == 1){
            int ans1 = 0, ans2 = 0;
            if(v[1].size()){ans1=s;ans1-=v[1][0];}
            if(v[2].size()>=2){ans2=s-v[2][0]-v[2][1];}
            return max(ans1,ans2);
        }
        else{
            int ans1 = 0, ans2 = 0;
            if(v[2].size())ans1=s-v[2][0];
            if(v[1].size()>=2)ans2=s-v[1][0]-v[1][1];
            return max(ans1,ans2);
        }
        return -1;
    }
};