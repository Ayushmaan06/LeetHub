class Solution {
public:
    int findWinningPlayer(vector<int>& skills, int k) {
        deque<int> dq;
        int n = skills.size();
        if (k >= n) {
            return (max_element(skills.begin(),skills.end())-skills.begin());
        }
        for (int i = 0; i < n; i++) {
            dq.push_back(skills[i]);
        }
        int win = 0, pw = skills[0];
        while (win < k) {
            int f = dq.front(); dq.pop_front();
            int s = dq.front(); dq.pop_front();
            int w = max(f, s), l = min(f, s);
            if (pw == w) {
                win++;
            } else {
                win = 1;
                pw = w;
            }
            dq.push_front(w);
            dq.push_back(l);
        }
        for (int i = 0; i < n; i++) {
            if (skills[i] == dq.front()) return i;
        }
        return -1;
    }
};
