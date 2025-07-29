class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& c) {
        int i=0,j=2;
        int n = c.size();
        int k=0;
        while(i<n){
            if(c[i]==c[j]&&c[(1+i)%n]!=c[i])k++;
            i++;
            j=(j+1)%n;
        }
        return k;
    }
};