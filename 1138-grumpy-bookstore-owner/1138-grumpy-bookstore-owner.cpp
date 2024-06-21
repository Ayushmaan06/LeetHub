class Solution {
public:
    int maxSatisfied(vector<int>& c, vector<int>& g, int m) {
        int i = 0 , j = 0 ,mx=0,a=0 , k;
        while(j<c.size()){
            if(j-i+1>m){
                mx=max(a,mx);
                if(mx==a)   k=i;
                if(g[i]==1) a-=c[i];
                i++;

            }
            if(g[j]==1) a+=c[j];
            j++;
        }
        mx = max(a, mx);
        int sum=0;
        for(int x=0;x<g.size();x++){
            if(g[x]==0) sum+=c[x];
        }
        sum+=mx;
        return sum;
        
    }
};