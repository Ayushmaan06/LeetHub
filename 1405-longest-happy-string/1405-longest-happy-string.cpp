class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int,char>> pq;
        if (a) pq.push({a,'a'});
        if (b) pq.push({b,'b'});
        if (c) pq.push({c,'c'});

        string s;

        while (!pq.empty()) {
            auto [cnt1, ch1] = pq.top();
            pq.pop();

            int n = s.size();
            if (n >= 2 && s[n-1] == ch1 && s[n-2] == ch1) {
                if (pq.empty()) break;

                auto [cnt2, ch2] = pq.top();
                pq.pop();

                s += ch2;
                cnt2--;

                if (cnt2 > 0) pq.push({cnt2, ch2});
                pq.push({cnt1, ch1});
            } else {
                s += ch1;
                cnt1--;
                if (cnt1 > 0) pq.push({cnt1, ch1});
            }
        }
        return s;
    }
};
