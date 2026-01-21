class Solution {
public:
    int s=0;
    void solve(vector<int>& v,int i,int cx){
        if(i==v.size()){s+=cx;return;}
        solve(v,i+1,cx);
        cx=cx^v[i];
        solve(v,i+1,cx);
    }
    int subsetXORSum(vector<int>& nums) {
        int cx=0;
        solve(nums,0,cx);
        return s;
    }
};