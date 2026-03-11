class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int zc=0,p=1,n=nums.size(),j=0,zi;
        for(int i : nums){
            if(i==0)zc++,zi=j;
            else p*=i;
            j++;
        }
        vector<int> res(n,0);
        if(zc>1)return res;
        if(zc==1) {res[zi]=p;return res;}
        int k=0;
        for(int i : nums)res[k++]=p/i;
        return res;        
    }
};