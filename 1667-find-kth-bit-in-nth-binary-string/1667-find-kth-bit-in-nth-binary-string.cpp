class Solution {
public:
    void rec(int k, vector<int>& v, int flag, int n, char& c) {
        if (k == 1) {
            c = (flag == 0) ? '0' : '1';
            return;
        }
        if (k > 1 && k < 5) {
            c = (flag == 0) ? '1' : '0';
            return;
        }
        if (k == v[n] / 2 + 1) {
            c = (flag == 0) ? '1' : '0';
            return;
        }
        if (k > v[n] / 2 + 1) {
            rec(v[n] - k + 1, v, flag ^ 1, n - 1, c); 
        } else {
            rec(k, v, flag, n - 1, c); 
        }
    }
    
    char findKthBit(int n, int k) {
        vector<int> v(n); 
        v[0] = 1;
        for (int i = 1; i < n; i++) {
            v[i] = 2 * v[i - 1] + 1;
        }
        
        char c;
        rec(k, v, 0, n - 1, c);
        return c;
    }
};
