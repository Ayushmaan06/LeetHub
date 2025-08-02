class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans=nums[0];
        int sc=0,i=0;
        for(int n : nums){
            if(n==ans)sc++;
            else sc--;
            if(sc<0){ans=n;sc=1;}
        }
        return ans;
    }
};