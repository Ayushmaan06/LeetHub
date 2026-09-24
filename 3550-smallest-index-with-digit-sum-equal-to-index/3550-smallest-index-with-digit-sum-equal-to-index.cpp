class Solution {
public:
    int s(int x){
        int res=0;
        string ss = to_string(x);
        for(char c: ss) res+=(c-'0');
        return res;
    }
    int smallestIndex(vector<int>& nums) {
        for(int i = 0 ; i < nums.size(); i++)
            if(i==s(nums[i]))return i;
        return -1;
    }
};