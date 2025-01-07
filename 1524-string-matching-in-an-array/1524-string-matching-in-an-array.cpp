class Solution {
public:
    bool isSubstring(const std::string& str1, const std::string& str2) {
        return str2.find(str1) != std::string::npos;
    }

    vector<string> stringMatching(vector<string>& words) {
        int n = words.size();
        set<string> ans;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j<n ; j++){
                if(isSubstring(words[j],words[i])&&i!=j)ans.insert(words[j]);
            }
        }
        vector<string> v(ans.begin(), ans.end());

        return v;
    }
};