class Solution {
public:
    int findMin(vector<int>& a) {
        int h=a.size()-1,l=0,m,ans=INT_MAX;
        while(l<=h){
            m= l+(h-l)/2;
            if(a[m]<a[h]){
                if(a[m]<ans)    ans=a[m];
                h=m-1;
            }
            else{
                if(a[l]<ans)    ans=a[l];
                l=m+1;
            }
        }
        return ans;
        
    }
};