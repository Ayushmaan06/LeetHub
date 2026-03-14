class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size(),h=-1;
        vector<int> r(n,-1);
        for(int i = n-1 ; i >= 0 ; i--){
            r[i]=h;
            h=max(h,height[i]);
        }h=height[0];
        int ans=0;
        for(int i = 1 ; i < n ; i++){
            if( h<=height[i]){h=max(h,height[i]);continue;}
            ans+=max(0,min(r[i],h)-height[i]);
        }
        return ans;
    }
};