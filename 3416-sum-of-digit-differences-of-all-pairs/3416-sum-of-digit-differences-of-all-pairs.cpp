class Solution {
public:
    long long sumDigitDifferences(vector<int>& nums) {
        long long ma=*max_element(nums.begin(),nums.end());
        long long l = log10(ma)+1;
        vector<vector<int>> v(l,vector<int>(10,0));
        for(int& n : nums){
            int i = 0;
            int e = n;
            while(e>0){
                v[i][e%10]++;
                i++;
                e/=10;
            }
        }
        long long ans=0;
        for(vector<int>& a : v){
            long long tc=0;
            for(int i = 0 ; i < 10 ; i++){
                tc+=a[i];
            }
            for(int i = 0 ; i < 10 ; i++){
                ans+=a[i]*(tc-a[i]);
            }

        }
        return ans/2;
    }
};