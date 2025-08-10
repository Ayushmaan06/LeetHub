class Solution {
public:
    bool reorderedPowerOf2(int n) {
        vector<int> v;
        while(n){
            v.push_back(n%10);
            n/=10;
        }
        sort(v.begin(),v.end());
        do {
            if(v[0]){
                int t=0;
                for(int i = 0 ; i < v.size() ; i++)t=t*10+v[i];
                if (t > 0 && (t & (t - 1)) == 0) return true;
            }
        } while (next_permutation(v.begin(), v.end()));
        return false;
    }
};