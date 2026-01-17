#define ll long long
class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bl, vector<vector<int>>& tr) {
        ll ans= INT_MIN;int n = bl.size();
        for(int i = 0 ; i < n ; i++){
            for(int j = i+1 ; j < n ; j++){
                ll bx1=bl[i][0],by1=bl[i][1];
                ll tx1=tr[i][0],ty1=tr[i][1];
                ll bx2=bl[j][0],by2=bl[j][1];
                ll tx2=tr[j][0],ty2=tr[j][1];
                if(bx1 >= tx2 || bx2 >= tx1)continue;
                if(by1 >= ty2 || by2 >= ty1)continue;
                ll x1 = max(bx1,bx2), x2 = min(tx1,tx2);
                ll y1 = max(by1,by2), y2 = min(ty1,ty2);
                ll s1 = x2-x1,s2=y2-y1,s=min(s1,s2);
                ans=max(ans,s*s);
            }
        }
        return ans == INT_MIN?0:ans;
    }
};