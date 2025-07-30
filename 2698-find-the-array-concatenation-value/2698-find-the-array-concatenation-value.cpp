class Solution {
public:
    long long findTheArrayConcVal(vector<int>& nums) {
        int n=nums.size();
        long long i=0,i1=n-1,ans=0;
        while(i<i1){
            int kk=log10(nums[i1])+1;
            int k = nums[i]*pow(10,kk);
            k+=nums[i1];
            ans+=k;
            i++;i1--;
        }
        if(n%2)ans+=nums[n/2];
        return ans;
    }
};