class Solution {
public:
    int numRescueBoats(vector<int>& p, int l) {
        int n = p.size();
        sort(p.begin(),p.end());
        int x = lower_bound(p.begin(),p.end(),l)-p.begin();
        int ans=n-x;
        vector<bool> v(x,false);
        int i=0,j=x-1;
        while(i<j){
            int s = p[i]+p[j];
            if(s<=l){
                ans++;
                v[i]=true;v[j]=true;
                i++;j--;
            }
            else j--;
        }
        for(bool f:v)
            if(!f)ans++;
        return ans;     
    }
};