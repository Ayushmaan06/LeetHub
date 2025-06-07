class Solution {
public:
    typedef pair<char, int> CPI;

    struct Compare {
        bool operator()(const CPI &a, const CPI &b) {
            if (a.first != b.first)
                return a.first > b.first; // min-heap for char
            return a.second < b.second;   // max-heap for int
        }
    };
    string remInd(string s, const vector<int>& indices) {
        unordered_set<int> idxSet(indices.begin(), indices.end());
        string result;

        for (int i = 0; i < s.size(); ++i) {
            if (idxSet.find(i) == idxSet.end()) {
                result += s[i];
            }
        }

        return result;
    }
    string clearStars(string s) {
        priority_queue<CPI, vector<CPI>, Compare> pq;
        int i = 0;
        vector<int> rem;
        for(char &c : s){
            if(c!='*')
                pq.push({c,i++});
            
            else{
                int r = pq.top().second;
                rem.push_back(r);
                pq.pop();
                rem.push_back(i++);
            }
        }
        return remInd(s,rem);

    }
};