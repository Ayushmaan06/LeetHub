class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int c=0;
        for(int i = 0 ; i < nums.size() ; i++){
            int k=nums[i]%3;
            if(k!=0)c+=1;
        }
        return c;
    }
};