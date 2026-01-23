class Solution {
public:
    vector<int> bs = vector<int>(32, 0);
    int add(int x,int y){
        for(int i = 0 ; i < 32 ; i++){
            if(y&(1<<i))bs[i]++;
        }
        int res=0;
        for(int i = 0 ; i < 32 ; i++){
            if(bs[i])res=res|(1<<i);
        }
        return res;
    }
    int sub(int x,int y){
        for(int i = 0 ; i < 32 ; i++){
            if(y&(1<<i) && bs[i])bs[i]--;
        }
        int res=0;
        for(int i = 0 ; i < 32 ; i++){
            if(bs[i])res=res|(1<<i);
        }
        return res;
    }
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int i = 0 , j = 0, n = nums.size(),cor=0,ans=INT_MAX;
        while(j<n){
            cor=add(cor,nums[j]);
            while(i<=j && cor>=k){
                ans=min(ans,j-i+1);
                cor=sub(cor,nums[i]);
                i++; 
            }
            j++;
        }
        return ans==INT_MAX?-1:ans;
    }
};