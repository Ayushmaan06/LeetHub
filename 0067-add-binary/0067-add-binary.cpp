class Solution {
public:
    string addBinary(string a, string b) {
        string r;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        int i = 0, j = 0, n = a.length(), m = b.length(), c = 0;

        while (i < n && j < m) {
            int x = a[i] - '0', y = b[j] - '0', s = x + y + c;
            if (s == 0) { r += '0'; c = 0; }
            else if (s == 1) { r += '1'; c = 0; }
            else if (s == 2) { r += '0'; c = 1; }
            else { r += '1'; c = 1; }
            i++; j++;
        }

        while (i < n) {
            int x = a[i] - '0', s = x + c;
            if (s == 0) { r += '0'; c = 0; }
            else if (s == 1) { r += '1'; c = 0; }
            else { r += '0'; c = 1; }
            i++;
        }

        while (j < m) {
            int x = b[j] - '0', s = x + c;
            if (s == 0) { r += '0'; c = 0; }
            else if (s == 1) { r += '1'; c = 0; }
            else { r += '0'; c = 1; }
            j++;
        }
        if (c) r += '1';   
        reverse(r.begin(), r.end());
        return r;
    }
};
