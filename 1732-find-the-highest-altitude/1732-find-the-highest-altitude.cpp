class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans = 0,p=0;
        for(int g : gain){
            ans=max({ans,p,p+g});
            p+=g;
        }
        return ans;
    }
};