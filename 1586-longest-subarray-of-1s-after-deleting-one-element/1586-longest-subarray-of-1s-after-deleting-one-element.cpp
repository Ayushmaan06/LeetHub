class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        if(n==1)return 0;
        for(int i = 0; i < n ; ){
            int t=0;
            while(i<n-1 && nums[i] == nums[i+1] && nums[i])
                t+=nums[i++];
            t+=nums[i];i++;
            ans.push_back(t);
        }
        int nn = ans.size(),res=-1;
        for(int i = 1 ; i < nn-1 ; i++){
            if(ans[i]==0) res=max(res,ans[i-1]+ans[i+1]);
        }
        for(int a : ans)res=max(res,a);
        if(ans.size()==1)return ans[0]-1;
        if(ans.size()==2)return max(ans[0],ans[1]);
        return res;
    }
};