class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hbars, vector<int>& vbars) {
        int i=0,j=0,h=0,v=0,nn=hbars.size(),mm=vbars.size();
        sort(hbars.begin(),hbars.end());sort(vbars.begin(),vbars.end());
        while(j<nn-1){
            if(hbars[j]+1 != hbars[j+1])i=j+1;
            h=max(h,j-i+1);
            j++;
        }
        i=0;j=0;
        while(j<mm-1){
            if(vbars[j]+1 != vbars[j+1])i=j+1;
            v=max(v,j-i+1);
            j++;
        }
        h=min(h,v)+2;
        return h*h;
    }
};