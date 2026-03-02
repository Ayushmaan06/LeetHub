class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        vector<int> v;
        int n = grid.size();
        for(vector<int> g : grid){
            bool f = false;
            for(int i = n-1 ; i>=0 ; i--){
                if(g[i]==1){v.push_back(i);f=true;break;}
            }
            if(!f)v.push_back(-1);
        }
        vector<int> t(v.begin(),v.end());
        sort(v.begin(),v.end());
        for(int i = 0 ; i < n ; i++)if(v[i]>i)return -1;
        int c=0;
        for(int i = 0 ; i < n ; i++){
            if(t[i]<=i)continue;
            int j = i;
            while(j<n && t[j]>i)j++;
            while(j>i){
                swap(t[j],t[j-1]);
                j--;
                c++;
            }
        }
        return c;
    }
};
//030230
//003230
//002330
//000233