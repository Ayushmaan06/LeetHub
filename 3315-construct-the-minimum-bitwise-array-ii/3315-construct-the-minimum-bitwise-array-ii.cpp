class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> res;
        for(int i : nums){
            if(i==2)res.push_back(-1);
            else{
                int j=0;
                while(i&(1<<j))j++;
                j--;
                int x = 1<<j;
                i=i^x;
                res.push_back(i);
            }
        }
        return res;
    }
};