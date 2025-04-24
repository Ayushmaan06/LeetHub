class Solution {
public:
    int solve(vector<int>& nums) {
        if(nums.empty()) return 0;
        if(nums.size() == 1) return nums[0];

        int prev2 = nums[0];  
        int prev1 = max(nums[0], nums[1]);  

        for (int i = 2; i < nums.size(); ++i) {
            int current = max(prev1, prev2 + nums[i]);
            prev2 = prev1;
            prev1 = current;
        }

        return prev1;
    }
    int rob(vector<int>& nums) {
        vector<int> t1,t2;
        if(nums.size()==1)return nums[0];
        int i = 0 ;
        for(int num : nums){
            if(i!=0)t1.push_back(num);
            if(i!=nums.size()-1)t2.push_back(num);
            i++;
        }
        return max(solve(t1),solve(t2));
    }
};