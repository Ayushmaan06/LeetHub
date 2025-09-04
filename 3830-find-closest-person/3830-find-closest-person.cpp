class Solution {
public:
    int findClosest(int x, int y, int z) {
        int o = abs(x-z), t = abs(y-z);
        if(o<t)return 1;
        if(o>t)return 2;
        return 0;
    }
};