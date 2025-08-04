class Solution {
public:
    long long factorial(int num) {
        long long fact = 1;
        for (int i = 2; i <= num; ++i) {
            fact *= i;
        }
        return fact;
    }

    // Function to calculate nCr
    long long calculate_nCr(int n, int r) {
        if (r < 0 || r > n) {
            return 0; // Invalid input for combinations
        }
        return factorial(n) / (factorial(r) * factorial(n - r));
    }
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int,int> mp;
        int n = nums.size();
        for(int i =0;i<n;i++){
            for(int j=i+1;j<n;j++){
                mp[nums[i]*nums[j]]++;
            }
        }
        int ans=0;
        for(auto& it : mp){
            if(it.second==2)ans+=8;
            else if(it.second>2){
                int c= calculate_nCr(it.second,2);
                ans+=c*8;
            }
            
        }
        return ans;
    }
};