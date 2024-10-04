class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(), skill.end());
        long long n = skill.size();
        long long l = 0 , r = n-1 , k = skill[0] + skill[n-1]; 
        long long m=0;
        while(l<r){
            if(skill[l]+skill[r] != k){
                return -1;
            }
            
            m+=skill[l]*skill[r];
            l++;
            r--;
        }
        return m;
    }
};