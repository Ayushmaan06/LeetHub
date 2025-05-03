class Solution {
public:
    int check(int x, vector<int>& tops, vector<int>& bottoms) {
        int n = tops.size();
        int r_top = 0, r_bottom = 0;
        for (int i = 0; i < n; ++i) {
            if (tops[i] != x && bottoms[i] != x) {
                return -1;  
            } else if (tops[i] != x) {
                r_top++;
            } else if (bottoms[i] != x) {
                r_bottom++;
            }
        }
        return min(r_top, r_bottom);
    }
    
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int r1 = check(tops[0], tops, bottoms);
        int r2 = check(bottoms[0],tops,bottoms);
        if(r1==-1&&r2==-1)return -1;
        if(r1==-1 || r2==-1)return max(r1,r2);
        else return min(r1,r2);
    }
};
