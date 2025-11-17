class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int c=-1,p=-1;
        int i = 0,n=nums.size();
        while(i<n && !nums[i])i++;
        c=i;
        if(i==n)return true;
        i++;
        for(;i<n;i++){
            if(nums[i]){if(i-c<=k)return false; c = i;}
        }
        return true;
    }
};