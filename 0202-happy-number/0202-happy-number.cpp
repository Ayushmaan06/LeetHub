class Solution {
public:
    int ss(int n){
        string s = to_string(n);int x=0;
        for(char c : s)x=x+(c-'0')*(c-'0');
        return x;
    }
    bool isHappy(int n) {
        unordered_set<int> s;
        while(n!=1){
            int x = ss(n);
            n=x;
            if(s.count(x))return false;
            s.insert(x);
        }
        return true;
    }
};
