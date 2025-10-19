class Solution {
public:
    void solve(unordered_set<string>& nw, vector<string>& w, unordered_map<char,int>& f, unordered_map<char,int>& sc,
               int csc, int& ans, int i, int n) {
        if(i == n) {
            ans = max(ans, csc);
            return;
        }
        string s = w[i];
        if(nw.count(s)) {
            solve(nw, w, f, sc, csc, ans, i + 1, n);
            return; 
        }
        int x = 0;
        bool ok = true;
        unordered_map<char,int> temp;
        for(char c : s) {
            if(f.find(c) == f.end()) { ok = false; break; } 
            x += sc[c];
            temp[c]++;
            if(temp[c] > f[c]) { ok = false; break; }
        }
        solve(nw, w, f, sc, csc, ans, i + 1, n);
        if(ok) {
            for(auto& it : temp) f[it.first] -= it.second;  // use letters

            solve(nw, w, f, sc, csc + x, ans, i + 1, n);    // include word

            for(auto& it : temp) f[it.first] += it.second;  // backtrack
        }
    }

    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        unordered_map<char,int> freq, sc;
        for(char c : letters) {
            freq[c]++;
        }
        for(int i = 0; i < 26; i++) {
            sc['a' + i] = score[i];
        }
        unordered_set<string> nw;
        for(string s : words) {
            bool ok = true;
            unordered_map<char,int> temp;
            for(char c : s) {
                temp[c]++;
                if(freq.find(c) == freq.end() || temp[c] > freq[c]) {
                    ok = false;
                    break;
                }
            }
            if(!ok) nw.insert(s);
        }
        int ans = 0;
        solve(nw, words, freq, sc, 0, ans, 0, words.size());
        return ans;
    }
};
