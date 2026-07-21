
class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {

        int origOnes = 0;
        for (char c : s) {
            if (c == '1')
                origOnes++;
        }
        

        string t = "1" + s + "1";
        int n = t.size();

        vector<pair<char,int>> runs;
        char currChar = t[0];
        int count = 1;
        for (int i = 1; i < n; i++) {
            if (t[i] == currChar) {
                count++;
            } else {
                runs.push_back({currChar, count});
                currChar = t[i];
                count = 1;
            }
        }
        runs.push_back({currChar, count});

        int maxGain = 0;
        for (size_t i = 0; i + 2 < runs.size(); i++) {
            if (runs[i].first == '0' && runs[i+1].first == '1' && runs[i+2].first == '0') {

                int gain = runs[i].second + runs[i+2].second;
                maxGain = max(maxGain, gain);
            }
        }

        return origOnes + maxGain;
    }
};
