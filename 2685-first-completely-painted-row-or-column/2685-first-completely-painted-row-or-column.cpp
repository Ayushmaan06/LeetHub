class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        long long n=mat.size(),m=mat[0].size();
        vector<long long> r(n,0),c(m,0);
        vector<pair<long long,long long>>g(m*n);
        for(long long i = 0 ; i < n ; i++){
            for(long long j=0;j<m;j++){
                r[i]+=mat[i][j];
                c[j]+=mat[i][j];
                g[mat[i][j]-1]={i,j};
            }
        }
        for(long long i = 0 ; i < arr.size();i++){
            auto[rr,cc]=g[arr[i]-1];
            r[rr]-=arr[i];
            c[cc]-=arr[i];
            if(r[rr]==0 || c[cc]==0)return i;
        }
        return -1;
    }
};