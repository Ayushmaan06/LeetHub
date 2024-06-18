class Solution {
public:
    bool ispal(const string& s) {
        int i = 0, j = s.length() - 1;
        while (i < j) {
            if (s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> k;
        for (int i = 0; i < (1 << (s.length() - 1)); i++) {
            string r;
            vector<string> v;int flag=0;
            for (int j = 0; j < s.length(); j++) {
                r += s[j];
                if ((i & (1 << j)) || j == s.length() - 1) {
                    if (ispal(r)) {
                        v.push_back(r);
                    }
                    else    flag=1;
                    r.clear();
                }
            }
            k.push_back(v);
            if(flag){
                k.pop_back();
                flag=0;
            }
        }
        return k;
    }
};

