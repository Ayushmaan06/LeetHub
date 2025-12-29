class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int ans=INT_MAX,n=nums.size(),l=*max_element(nums.begin(),nums.end()),h=accumulate(nums.begin(),nums.end(),0);
        while(l<=h){
            int m = l + (h-l)/2;
            int c = 1,s = 0;
            for(int i : nums){
                if(s+i>m){
                    c++;s=0;
                }
                s+=i;
            }
            if(c<=k)ans=m,h=m-1;
            else l = m+1;
        }
        return ans;
    }
};