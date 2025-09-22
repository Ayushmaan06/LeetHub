class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans=0;
        bool og=true;
        for(int i : nums){
            if(i){
                if(!og)ans++,og=!og;
            }
            else{
                if(og)ans++,og=!og;
            }
        }
        return ans;
    }
};