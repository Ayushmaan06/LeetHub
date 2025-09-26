class Solution {
public:
    int minCostToMoveChips(vector<int>& pp) {
        int n=pp.size(),oc=0;
        for(int p : pp)if(p%2)oc++;
        return min(n-oc,oc);
    }
};