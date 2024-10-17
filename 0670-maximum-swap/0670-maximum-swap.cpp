class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        int n = s.size();
        vector<int> maxIdx(n);
        

        int maxPos = n - 1;
        maxIdx[maxPos] = maxPos;
        for (int i = n - 2; i >= 0; --i) {
            if (s[i] > s[maxPos]) {
                maxPos = i;
            }
            maxIdx[i] = maxPos;
        }

        for (int i = 0; i < n; ++i) {
            if (s[maxIdx[i]] != s[i]) {

                swap(s[i], s[maxIdx[i]]);
                break;
            }
        }
        
        return stoi(s);
    }
};
