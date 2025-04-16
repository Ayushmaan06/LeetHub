class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        //n * n-1 / 2
        int n = nums.size();
        int ca=0;
        unordered_map<int,int> c;
        long long ans=0;
        int r=0;
        for(int l = 0 ; l<n ;l++){
            while(ca<k && r<n){
                ca+=c[nums[r]];
                c[nums[r]]+=1;
                r++;
            }
            if(ca>=k)ans+=n-r+1;
            c[nums[l]]-=1;
            ca-=c[nums[l]];
        }
        return ans;
    }
};