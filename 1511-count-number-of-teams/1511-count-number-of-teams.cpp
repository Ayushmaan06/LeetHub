class Solution {
public:
    int numTeams(vector<int>& a) {
        std::ios::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(NULL);
        int n = a.size(), c=0;
        for(int i = 0 ; i < n ; i ++){
            int sl=0 , lr = 0,ll,sr;
            for(int j = 0 ; j<n ; j++){
                if(j<i && a[j]<a[i]){
                    sl++;
                }
                if(j>i && a[j]>a[i]){
                    lr++;
                }
            }
            ll=i-sl;sr=n-i-1-lr;
            c+=sl*lr + ll*sr;
        }
        return c;
    }
};