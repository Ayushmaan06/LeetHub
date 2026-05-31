class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(),asteroids.end());
        long long m = mass;
        for(int a : asteroids){
            if(a<=m)m+=a;
            else return false;
        }
        return true;
    }
};