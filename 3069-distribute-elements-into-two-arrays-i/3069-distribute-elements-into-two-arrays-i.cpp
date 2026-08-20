class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> n1,n2;
        n1.push_back(nums[0]); n2.push_back(nums[1]);
        for(int i = 2 ; i < nums.size() ; i++){
            if(n1[n1.size()-1]>n2[n2.size()-1])n1.push_back(nums[i]);
            else n2.push_back(nums[i]);
        }
        for(int i : n2)n1.push_back(i);
        return n1;
    }
};