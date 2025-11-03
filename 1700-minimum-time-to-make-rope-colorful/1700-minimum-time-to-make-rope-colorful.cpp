class Solution {
public:
    int minCost(string colors, vector<int>& need) {
        int n = colors.size(),ans=0;
        for(int i = 0 ; i < n ; ){
            int ma=-1,sum=0,j=i;
            while(colors[j]==colors[i]){
                ma=max(ma,need[j]);
                sum+=need[j];
                j++;
            }
            if(j>i+1)ans+=sum-ma;
            i=j;
        }
        return ans;
    }
};