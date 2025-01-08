class Solution {
public:
    bool ips(string s1, string s2){
        if(s1.length() > s2.length()) return false;
        int n = s1.length(), n1 = s2.length();
        
        for(int i = 0; i < n; i++){
            if(s1[i] != s2[i]) return false;
        }

        for(int i = 0; i < n; i++){
            if(s1[i] != s2[n1 - n + i]) return false;
        }

        return true;
    }
    
    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size(), ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                if(ips(words[i], words[j]) && i != j) ans++;
            }
        }
        return ans;
    }
};
