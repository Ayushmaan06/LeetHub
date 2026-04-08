#define ll long long
class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int mod=1e9+7;
        for(vector<int> &q : queries){
            int l = q[0],r=q[1],k=q[2],v=q[3];
            while(l<=r){
                nums[l]=(int)(((ll)nums[l]*v)%mod);
                l+=k;
            }
        }
        int x=0;
        for(int n : nums)x=x^n;
        return x;
    }
};