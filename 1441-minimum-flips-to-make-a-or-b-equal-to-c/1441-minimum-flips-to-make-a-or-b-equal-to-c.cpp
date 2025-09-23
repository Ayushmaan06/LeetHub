class Solution {
public:
    int minFlips(int a, int b, int c) {
        int i = 0, ans = 0;
        while ((a >= (1<<i)) || (b >= (1<<i)) || (c >= (1<<i))) {
            int w = 1 << i;
            int x = a & w, y = b & w, z = c & w;
            if (z) {
                if (!x && !y) ans++;
            } else {
                if ((!x && y) || (x && !y)) ans++;
                if (x && y) ans += 2;
            }
            i++;
        }
        return ans;
    }
};
