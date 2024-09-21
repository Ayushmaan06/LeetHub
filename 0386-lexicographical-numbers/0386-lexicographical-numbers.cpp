class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> v;
        int current = 1;
        
        for (int i = 0; i < n; ++i) {
            v.push_back(current);
            if (current * 10 <= n) {
                current *= 10;
            } else {
                if (current >= n) current /= 10;
                current++;
                while (current % 10 == 0) current /= 10;
            }
        }
        
        return v;
    }
};