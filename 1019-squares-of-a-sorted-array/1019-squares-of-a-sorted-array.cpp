class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int z = lower_bound(nums.begin(),nums.end(),0)-nums.begin(),n=nums.size();
        vector<int> res;
        int i1=-1,i2=z;
        if(z>0)i1=z-1;
        if(n==1)return {nums[0]*nums[0]};
        while(i1>=0 && i2<n){
            if(nums[i1]*nums[i1]<nums[i2]*nums[i2]){
                res.push_back(nums[i1]*nums[i1]);
                i1--;
            }
            else{
                res.push_back(nums[i2]*nums[i2]);
                i2++;
            }
        }
        while(i1>=0){
            res.push_back(nums[i1]*nums[i1]);
            i1--;
        }
        while(i2<n){
            res.push_back(nums[i2]*nums[i2]);
            i2++;
        }
        return res;
    }
};